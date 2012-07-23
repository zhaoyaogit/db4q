/*
 * $Id: test1.cpp 1 2012-01-17 02:31:57Z  $
 */
/*
 * ����ThreadPool
 */
#include "ThreadPool.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class SendMessage : public LWPR::WorkRequest
{
public:
	void DoWork()
	{
		cout << __FUNCTION__ << LWPR::Thread::GetCurrentThreadId() << endl;
	}

private:
};


/**
 * ������
 */
int main(int argc, char *argv[])
{
	LWPR::THREAD_POOL_OPTION_T opt;
	LWPR::ThreadPool* pool = new LWPR::ThreadPool(opt);
	SendMessage* req = new SendMessage;

	pool->AddRequest(req);

	sleep(1);

	pool->AddRequest(req);

	sleep(3);

	pool->AddRequest(req);

	sleep(1000000);
	return 0;
}

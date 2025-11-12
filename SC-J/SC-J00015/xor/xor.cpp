#include <bits/stdc++.h>
using namespace std;
long a[500050],n,k;
long a_num0()
{
	long cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			cnt++;
		}
	}
	return cnt;
}
long a_num1()
{
	long cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			cnt++;
		}
	}
	return cnt;
}
bool a_01()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>1)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%ld%ld",&n,&k);
	for(long i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
	}
	if(k==0 && a_01())
	{
		printf("%ld",a_num0()+a_num1()/2);
	}
	else if(k==1 && a_01())
	{
		printf("%ld",a_num1());
	}
	else
	{
		
	}

	return 0;
}
#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int a[5000];
long long b,sum,cnt;
bool truep(int sump,int maxp)
{
	return sump>2*maxp;
}
bool stepb(int step)
{
	return long(b/pow(2,step))%2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int max=0;
		for(int j=0;j<pow(2,i);j++)
		{
			if(stepb(j))
			{
				sum+=a[i];
				if(max<a[i])
				{
					max=a[i];
				}
			}
		}
		if(truep(sum,max))
		{
			cnt++;
		}
		b++;
	}
	cout<<cnt;
	return 0;
}

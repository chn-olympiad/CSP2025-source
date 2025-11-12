#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath> 
using namespace std;
int a[105]={};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int R=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		int m2=i/m;
		if(m2%2==1)
		{
			int maxm=2*n*((m2-1)/2)+1;
			int cnt1=1;
			for(int j=maxm;j<=maxm+n-1;j++)
			{
				if(a[j]==R)
				{
					cout<<i/m<<" "<<cnt1;
					return 0;
				}
				cnt1++;
			}
			i+=n;	
		}
		else
		{
			int minm=2*n*((m2-1)/2)+n+1;
			int cnt2=n;
			for(int j=minm;j<=minm+n-1;j++)
			{
				if(a[j]==R)
				{
					cout<<i/m<<" "<<cnt2;
					return 0;	
				}
				cnt2--;
			}
		}
	}
	return 0;
}

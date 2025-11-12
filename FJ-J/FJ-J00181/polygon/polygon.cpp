#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n,a[5005],cnt=0;
int main()
{
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int maxn=0,ncnt=0;
		for (int j=1;j<=n;j++)
		{
			maxn=max(maxn,a[j]);
			ncnt+=a[j];
		}
		if (ncnt>maxn*2)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0; 
}

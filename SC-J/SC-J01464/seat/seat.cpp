#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int l=1;l<=n;l++)
			{
				if(a[n*i-n+l]==sum)
				{
					cout<<i<<' '<<l;
					return 0;
				}
			}
		}
		else
		{
			for(int l=1;l<=n;l++)
			{
				if(a[n*i-n+l]==sum)
				{
					cout<<i<<' '<<n-l+1;
					return 0;
				}
			}
		}
	}
	return 0;
}

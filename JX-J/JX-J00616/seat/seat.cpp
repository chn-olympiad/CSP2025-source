#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m*n+1];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int h=a[1];
	for(int k=1;k<=10000;k++)
	{
		for(int i=1;i<=m*n;i++)
		{
			if(a[i]>=a[i-1])
			{
				swap(a[i],a[i-1]);
			}
		}
	}
	int o,q;
	for(int i=1;i<=m;i++)
	{
		if(a[i]==h)
		{
			if(i%m==0)
			{
				o=i/m;
			}
			else
			{
				o=i/m+1;
			}
			if(i%2!=0)
			{
				q=i%m;
			}
			else
			{
				q=n-i%m+1;
			}
			cout<<o<<" "<<q;
			return 0;
		}
	}
	return 0;
}

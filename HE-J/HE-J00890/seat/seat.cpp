#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	int a[100005],l,r;
	cin>>n>>m;
	int k,s;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		k=a[1];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[j]>a[i])
			{
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			s=i;
		}
		if(s>n)
		{
			if(s%n==0)
			{
				l=s/n;
			}
			else
			{
				l=s/n+1;
			}
		}
		else
		{
			l=1;
		}
		if(s==n)
		{
			r=n;
		}
		else if(s-n==1)
		{
			r=n;
		}
		else 
		{
			r=s%n;
		}
	}
	cout<<l<<" "<<r;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			s++;
		}
	}
	if(s%n==0)
	{
		m=s/n;
		if(m%2==0)
		{
			n=1;
		}
		cout<<m<<" "<<n;
	}
	else
	{
		m=s/n+1;
		if(m%2==0)
		{
			n=n-s%n+1;
		}
		else
		{
			n=s%n;
		}
		cout<<m<<" "<<n;
	}
	return 0;
}
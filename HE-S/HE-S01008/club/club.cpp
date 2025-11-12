#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,q=0,m=0,p=0;
	cin>>n;
	cin>>t;
	for(int i=1;i<=3*n*t-2;i++)
	{
		cin>>a[i];
	} 
	max(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			p+=a[i];
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-2])
		{
			m+=a[i];
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i+1])
		{
			q+=a[i];
		}
	}
	cout<<p<<endl<<m<<endl<<q;
	return 0;
} 

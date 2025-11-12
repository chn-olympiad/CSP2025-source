#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505],t,tmp;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i])tmp=i;
	}
	if(tmp%n>0)
	{
		int b=(tmp-1)/n+1;
		if(b%2==1)
		{
			cout<<b<<" "<<tmp%n;
		}
		else
		{
			cout<<b<<" "<<n-(tmp%n)+1;
		}
	}
	else
	{
		int b=tmp/n;
		if(b%2==1)
		{
			cout<<b<<" "<<n;
		}
		else
		{
			cout<<b<<" "<<1;
		}
	}
	return 0;
}

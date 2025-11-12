#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans,c,r;
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
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			ans=i;
		}
	}
	c=ceil(1.0*ans/n);
	r=ans%n;
	if(ans%n==0)
	{
		r=n;
	}
	if(c%2==0)
	{
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

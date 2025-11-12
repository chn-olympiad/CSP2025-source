#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,c;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			c=n*m-i+1;break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(c<=i*n && i%2!=0)
		{
			cout<<i<<" "<<c-(i-1)*n;
			break;
		}
		if(c<=i*n && i%2==0)
		{
			cout<<i<<" "<<i*n-c+1;
			break;
		}
	}
	return 0;
}
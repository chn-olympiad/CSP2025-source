#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k,l,u;
bool cmp(int x,int y)
{
	return x>y;
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
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			l=i;
			break;
		}
	}
	if(l%n!=0)
	u=l/n+1;
	else
	u=l/n;
	cout<<u<<" ";
	if(u%2!=0)
	{
		cout<<l-(u-1)*n;
	}
	else
	{
		cout<<n-l+(u-1)*n+1;
	}
	return 0;
}
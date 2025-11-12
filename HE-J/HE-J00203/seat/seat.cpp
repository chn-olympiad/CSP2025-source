#include <bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],p,q;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	p=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==p)
		{
			q=n*m-i;
			break;
		}
	}
	int d=q/n,f=q%n;
	if(d%2==1&&f!=0)
	{
		cout<<d+1<<" "<<n-f+1;
	}
	if(d%2==0&&f!=0)
	{
		cout<<d+1<<" "<<f;
	}
	if(d%2==1&&f==0)
	{
		cout<<d<<" "<<n;
	}
	if(d%2==0&&f==0)
	{
		cout<<d<<" "<<1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,p=0,c;
int a[201];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1 && m==1) 
	{
		cout<<1<<' '<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int st=a[1];
	sort(a+1,a+n*m+1);
	if(st==a[n*m])
	{
		cout<<1<<' '<<1;
		return 0;
	}
	if(st==a[1])
	{
		cout<<m<<' '<<n;
		return 0;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==st)
		{
			p=(n*m-i+1);
			break;
		}
	} 
	if(p%n==1) c=p/n+1;
	if(p%n==0) c=p/n;
	int h=c%2;
	if(h==1)
	{
		int l=(p%n)==0?n:(p%n);
		cout<<c<<' '<<l;
		return 0;
	}
	if(h==0)
	{
		int l;
		if(p%n==0) l=m-(n-1);
		else l=m-(p%n-1);
		cout<<c<<' '<<l;
		return 0;
	}
	return 0;
}

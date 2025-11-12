#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xr,nm;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++) cin>>a[i];
	xr=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++)
	{
		if(a[i]==xr)
		{
			xr=i;
			break;
		}
	}
	int h=0,l=0;
	if(xr%n==0) l=xr/n;
	else l=xr/n+1;
	if(xr%n==0)
	{
		if(l%2) h=n;
		else h=1;
	}
	else
	{
		if(l%2) h=xr%n;
		else h=n-(xr%n)+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

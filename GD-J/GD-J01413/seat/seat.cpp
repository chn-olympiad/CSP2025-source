#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll n,m;
ll a[N];
ll ansx,ansy;
ll xx,yy=1;
ll d=0;
ll fx[2]={1,-1};
ll xr;
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1,greater<int> ());
	for(int i=1;i<=n*m;i++)
	{
		if(xx==n && d==0)
		{
			yy++;
			d=1;
		}
		else if(xx==1 && d==1)
		{
			yy++;
			d=0;
		}
		else
		{
			xx+=fx[d];
		}
		if(a[i]==xr)
		{
			ansx=xx,ansy=yy;
			break;
		}
	}
	cout<<ansy<<' '<<ansx;
	return 0;
}

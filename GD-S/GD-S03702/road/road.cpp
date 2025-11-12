#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,c,a,zx=LLONG_MAX,zd=LLONG_MIN; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++) cin >> u >> v >> w;
	for(int i=1;i<=k;i++)
	{
		ll s=0;
		cin >> c;
		zd=max(zd,c);
		s+=c;
		for(int j=1;j<=n;j++)
		{
			cin >> a;
			zd=max(zd,a);
			s+=a;
		}
		zx=min(zx,s);
	}
	if(zd==0) cout << 0;
	else cout << zx;

	return 0;
}
/*
Rp++ 
T2Í¼ÂÛ yuck
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int n,m,k,ans;
int w[N],c[N];
vector <int>a[N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,o;
		scanf("%lld%lld%lld",&u,&o,&w[i]);
		a[u].push_back(o);
		a[o].push_back(u);
		ans+=w[i];
	}
	for(int i=1;i<=n+1;i++)
	{
		scanf("%lld",&c[i]);
		ans+=c[i];
	}
	cout<<ans;
	return 0; 
}

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,a[11][10005],c[11],ans,vis[10005],cnt;

vector<pair<int,int> >u[10005];

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		scanf("%lld%lld%lld",&uu,&vv,&ww);
		cnt+=ww;
		pair<int,int>pa=make_pair(vv,ww),pb=make_pair(uu,ww);
		u[uu].push_back(pa);
		u[vv].push_back(pb);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c);
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	printf("%lld",cnt);
	return 0;
}

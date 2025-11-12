#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k,cnt;
int c[N];
vector<int> g[N];
ll ans;
bool b[N];
int a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) c[i]=INT_MAX;
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		c[u]=min(c[u],w);
		c[v]=min(c[v],w);
		g[u].push_back(v);
		g[v].push_back(u);
		cnt=max(cnt,w);
		ans+=w;
	}
	while(k--){
		int f;
		scanf("%d",&f);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	}
	ll sum=cnt;
	printf("%lld",ans-sum);
	return 0;
}

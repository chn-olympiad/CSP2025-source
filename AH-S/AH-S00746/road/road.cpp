#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=3e4+100, maxM=3e6+100;
ll n,m,k,ans=LLONG_MAX;
ll cnt_edge, cnt_side, cnt_n;
ll fa[maxn];
ll c[20], a[20][maxn];
ll flag[20];
struct node {
	ll u,v,w;
}edge[maxM], side[maxM];

bool cmp(node a,node b) {
	return a.w<b.w;
}

ll Find (ll u) {
	if (fa[u]==u) return u;
	return fa[u]=Find(fa[u]); 
}

void work() {
	ll sum=0;
	cnt_side=m;
	cnt_n=n;
	for (int i=1; i<=m; i++) 
		side[i]=edge[i];
	for (int i=1; i<=k; i++)
		if (flag[i]==1) {
			sum+=c[i];
			cnt_n++;
			for (int j=1; j<=n; j++) 
				side[++cnt_side].u=cnt_n, side[cnt_side].v=j, side[cnt_side].w=a[i][j];
		}
	sort(side+1, side+cnt_side+1, cmp);
	for (int i=1; i<=cnt_n; i++)
		fa[i]=i;
	for (int i=1; i<=cnt_side; i++) {
		ll u=Find(side[i].u), v=Find(side[i].v), w=side[i].w;
		if (u==v) continue;
		sum+=w;
		fa[u]=v;
	}
	ans=min(ans, sum);
}

void dfs(ll cnt) {
	if (cnt>k) 
		{ work(); return ; }
	flag[cnt]=1; dfs(cnt+1);
	flag[cnt]=0; dfs(cnt+1);
	
}
int main() {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++) {
		ll u,v,w; cin>>u>>v>>w;
		edge[++cnt_edge].u=u, edge[cnt_edge].v=v, edge[cnt_edge].w=w;
	}
	bool all_flag=true;
	for (int i=1; i<=k; i++) {
		cin>>c[i];
		if (c[i]!=0) all_flag=false;
		ll have_find=0;
		for (int j=1; j<=n; j++) {
			cin>>a[i][j];
			if (a[i][j]==0) have_find++;
		}
		if (have_find<1) all_flag=false;
	}
	if (all_flag&&k!=0) {
		for (int i=1; i<=k; i++)
			flag[i]=1;
		work();
	}
	else 
		dfs(1);
	cout<<ans;
	return 0;
}

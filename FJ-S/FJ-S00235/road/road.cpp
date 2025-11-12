#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 10005
#define M 1000005
#define INF (ll)1e18

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
}
ll n, m, k, a[N][N], pre[N][N], dp[N][1<<10], c[15][N], pre1[15][N], ans;
ll fa[N], head[N], tot, dfn[N], id[N], cnt, num, dep[N], sz[N];
struct Node{
	ll u, v, w;
}q[M], q1[N];
struct Edge{
	ll to, nxt;
}e[N<<1];
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void add(ll x, ll y){
	e[++tot]={y, head[x]}, head[x]=tot;
}
void dfs(ll x, ll fa){
	dfn[x]=++num, id[num]=x, dep[x]=dep[fa]+1, sz[x]=1;
	for(int i=head[x]; i; i=e[i].nxt){
		ll y=e[i].to;
		if(y==fa) continue;
		dfs(y, x);
		sz[x]+=sz[y];
	}
}
struct TNode{
	ll l, r, minn;
};
struct Tree{
	TNode t[N<<2];
	void build(ll p, ll l, ll r, ll pos){
		t[p].l=l, t[p].r=r;
		if(l==r) return t[p].minn=c[pos][id[l]], void();
		ll mid=(l+r)>>1;
		build(p<<1, l, mid, pos);
		build(p<<1|1, mid+1, r, pos);
		t[p].minn=min(t[p<<1].minn, t[p<<1|1].minn); 
	}
	ll query(ll p, ll nl, ll nr){
		ll l=t[p].l, r=t[p].r;
		if(nl<=l&&nr>=r) return t[p].minn;
		ll mid=(l+r)>>1, res=INF;
		if(nl<=mid) res=min(res, query(p<<1, nl, nr));
		if(nr>mid) res=min(res, query(p<<1|1, nl, nr));
		return res;
	}
}T[10];
void solve1(){
	ans=0;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) q[i]={rd(), rd(), rd()};
	sort(q+1, q+m+1, [](Node x, Node y){return x.w<y.w;});
	for(int i=1; i<=m; i++){
		ll x=find(q[i].u), y=find(q[i].v);
		if(x==y) continue;
		fa[x]=y, ans+=q[i].w;
	}
	printf("%lld\n", ans);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=rd(), m=rd(), k=rd();
	if(k==0) return solve1(), 0;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) q[i]={rd(), rd(), rd()};
	sort(q+1, q+m+1, [](Node x, Node y){return x.w<y.w;});
	for(int i=1; i<=m; i++){
		ll x=find(q[i].u), y=find(q[i].v);
		if(x==y) continue;
		fa[x]=y, ans+=q[i].w;
		add(q[i].u, q[i].v), add(q[i].v, q[i].u);
		q1[++cnt]={q[i].u, q[i].v, q[i].w};
	}
//	puts("awa");
	dfs(1, 0);
//	for(int i=1; i<=n; i++) cout<<dfn[i]<<' ';
//	puts("awa");
	for(int i=1; i<=k; i++){
		c[i][0]=rd();
		for(int j=1; j<=n; j++) c[i][j]=rd();
		T[i].build(1, 1, n, i);
//		cout<<T[i].query(1, 2, n)<<endl;
	}
//	cout<<ans<<endl;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0]=0; 
//	for(int s=0; s<(1<<k); s++){
//		dp[0][s]=0;
////		dp[0][s]=ans;
//		for(int j=1; j<=k; j++){
//			if(!(s&(1<<(j-1)))) continue;
//			dp[0][s]+=c[j][0];
//		}
////		cout<<dp[1][s]<<' '; 
//	} 
//	puts("awa");
//	for(int s=0; s<(1<<k); s++) dp[0][s]=ans;
	for(int i=1; i<=cnt; i++){
//		cout<<q1[i].u<<' '<<q1[i].v<<' '<<q1[i].w<<endl;
		for(int s=0; s<(1<<k); s++){
			dp[i][s]=dp[i-1][s]+q1[i].w;
			for(int j=1; j<=k; j++){
				if(!(s&(1<<(j-1)))) continue;
				ll x=q1[i].u, y=q1[i].v, w=q1[i].w;
				if(dep[x]>dep[y]) swap(x, y);
				if(dep[x]<dep[y]) dp[i][s]=min(dp[i][s], dp[i-1][s]+T[j].query(1, dfn[y], dfn[y]+sz[y]-1)+min(T[j].query(1, 1, dfn[x]-1), T[j].query(1, dfn[x]+sz[x], n)));
			}
//			cout<<dp[i][s]<<endl;
			for(int j=1; j<=k; j++){
				if(!(s&(1<<(j-1)))) continue;
				ll x=q1[i].u, y=q1[i].v, w=q1[i].w;
//				cout<<min(T[j].query(1, 1, dfn[x]), T[j].query(1, dfn[x]+sz[x], n))<<endl;
				if(dep[x]>dep[y]) swap(x, y);
				if(dep[x]<dep[y]) dp[i][s]=min(dp[i][s], dp[i-1][s^(1<<(j-1))]+T[j].query(1, dfn[y], dfn[y]+sz[y]-1)+min(T[j].query(1, 1, dfn[x]-1), T[j].query(1, dfn[x]+sz[x], n))+c[j][0]);
			}
//			cout<<dp[i][s]<<' ';
		}
//		puts("");
	}
//	cout<<dp[n][1]<<endl;
	for(int s=0; s<(1<<k); s++) ans=min(ans, dp[cnt][s]);
	printf("%lld\n", ans); 

	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/


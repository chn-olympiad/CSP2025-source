#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+15,M = 1e6+5;
int fa[N];
int find(int x){return fa[x]==x?x:fa[x] = find(fa[x]);}
int n,m,k,c[15],a[15][N],ct,as,ans;
struct node{
	int u,v,w;
	int pf;
}x[M*2];
bool cmp(node a,node b){
	return a.w<b.w;
}
bool f[15],ft[M];
void dfs(int t){
	if(t>k){
		for(int i = 1;i<=n+k;i++)fa[i] = i;
		as = 0;
		for(int i = 1;i<=k;i++)if(f[i])as+=c[i];
		for(int i = 1;i<=m;i++){
			if(x[i].pf!=0&&!f[x[i].pf])continue;
			if(find(x[i].u)!=find(x[i].v)){
				fa[find(x[i].u)] = find(x[i].v);
				as+=x[i].w;
			}
		}
		ans = min(ans,as);
		return;
	}
	f[t] = 1;
	dfs(t+1);
	f[t] = 0;
	dfs(t+1);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<=n;i++)fa[i] = i;
	for(int i = 1;i<=m;i++){
		cin >> x[i].u >> x[i].v >> x[i].w;
		x[i].pf = 0;
	}
	sort(x+1,x+m+1,cmp);
	ct = 1;
	for(int i = 1;ct<n;i++){
		if(find(x[i].u)!=find(x[i].v)){
			ft[i] = 1;
			fa[find(x[i].u)] = find(x[i].v);
			ans+=x[i].w;
			ct++;
		}
	}
	ct = 0;
	for(int i = 1;i<=m;i++){
		if(!ft[i])continue;
		x[++ct] = x[i];
	}
	m = ct;
	for(int i = 1;i<=k;i++){
		cin >> c[i];
		for(int j = 1;j<=n;j++){
			cin >> a[i][j];
			x[++m] = {i+n,j,a[i][j],i};
		}
	}
	sort(x+1,x+m+1,cmp);
	dfs(1);
	cout << ans;
	return 0;
}


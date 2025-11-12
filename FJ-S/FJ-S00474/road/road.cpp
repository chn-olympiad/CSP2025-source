#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w;
}
const int MAXN = 2e4 + 8;
const int MAXM = 1e6 + 8;
int n,m,k,fa[MAXN],c[MAXN],ans = 1e15;
vector<PII> g[MAXN];
bool vis[MAXN];
struct node{
	int u,v,w;
}E[MAXM];
bool cmp(node x,node y){
	return x.w < y.w;
}
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int u,int num,bool *vis){
	bool flag = true;
	for(int i = 1;i <= n;i++)
		if(!vis[i]){
			flag = false;
			break;
		}
	if(flag){
		ans = min(ans,num);
		return;
	}
	for(auto y : g[u]){
		int v = y.first,w = y.second;
		if(vis[v]) continue;
		vis[v] = 1; 
		if(v > n) dfs(v,num + w + c[v - n],vis);
		else dfs(v,num + w,vis);
		vis[v] = 0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();m = read();k = read();
	if(k == 0){
		int cnt = 0;ans = 0;
		for(int i = 1;i <= n;i++) fa[i] = i;
		for(int i = 1;i <= m;i++){
			E[++cnt].u = read();E[cnt].v = read();E[cnt].w = read();
		}
		sort(E + 1,E + m + 1,cmp);
		for(int i = 1;i <= m;i++){
			int A = find(E[i].u),B = find(E[i].v);
			if(A == B) continue;
			fa[A] = B;
			ans += E[i].w;
		}
		cout << ans << "\n";
	}
	else{
		for(int i = 1;i <= m;i++){
			int u,v,w;u = read();v = read();w = read();
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		for(int i = 1;i <= k;i++){
			c[i] = read();
			for(int j = 1;j <= n;j++){
				int x;x = read();
				g[i + n].push_back({j,x});
				g[j].push_back({i + n,x});
			}
		}
		vis[1] = 1;
		dfs(1,0,vis);
		cout << ans << "\n";
	}
	return 0;
}


#include <bits/stdc++.h>
#define ll long long
const int N = 2e6+10;
using namespace std;
int n,m,k,c,u,v,w,cnt,fa[N];
ll ans = 0;
struct T{
	int u,v,w;
	bool operator < (T b){
		return w < b.w;
	}
}edge[N];
int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n+k;i++)
		fa[i] = i;
	for(int i = 1;i <= m;i++)
		cin >> u >> v >> w,edge[++cnt] = {u,v,w};
	for(int i = 1;i <= k;i++){
		cin >> c;
		ans += c;
		for(int j = 1;j <= n;j++){
			cin >> w,edge[++cnt] = {i+n,j,w};
		}
	}
	sort(edge+1,edge+cnt+1);
	int tmp = 0;
	for(int i = 1;i <= cnt;i++){
		int tu = edge[i].u,tv = edge[i].v,tw = edge[i].w;
		tu = find(tu),tv = find(tv);
		if(tu != tv){
			ans += tw;
			fa[tu] = tv;
			tmp++;
		}
		if(tmp == n+k-1){
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}


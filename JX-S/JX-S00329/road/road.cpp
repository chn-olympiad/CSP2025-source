#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dist[1510],conne[1510][20],ans;
int n,m,k,newss[1510],fa[1510];
bool vis[1510];
struct Edge{
	int a,b;
	ll w;
}edge[1000010];
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(vis,1,sizeof vis);
	for(int i = 1;i <= n + 100;i ++)
		for(int j = 1;j < 15;j ++)
			conne[i][j] = INF;
	for(int i = 1;i <= n + 100;i ++) fa[i] = i;
	for(int i = 1;i <= m;i ++){
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
	}
	sort(edge + 1,edge + m + 1,cmp);
	for(int i = 1;i <= k;i ++){
		cin >> newss[i];
		for(int j = 1;j <= n;j ++){
			ll w;
			cin >> w;
			conne[j][i] = w;
		}
	}
	for(int i = 1;i <= m;i ++){
		int x = edge[i].a,y = edge[i].b,xa = find(edge[i].a),ya = find(edge[i].b);
		ll w = edge[i].w;
		if(xa != ya){
			bool tt = 0;
			for(int j = 1;j <= k;j ++){
				if(conne[x][j] + conne[y][j] + vis[j] * newss[j] <= w|| conne[xa][j] + conne[ya][j] + vis[j] * newss[j] <= w){
					vis[j] = 0;
					tt = 1;
					ans += min(conne[x][j] + conne[y][j] + vis[j] * newss[j],conne[xa][j] + conne[ya][j] + vis[j] * newss[j]);
					fa[n + j] = xa;
					fa[xa] = ya;
				}
			}
			if(!tt){
				fa[xa] = ya;
				ans += w;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
 * start time:  22:28
 * end time:    2:28
 * 
 * rp++
*/

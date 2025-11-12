
/**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{int v, w;};
struct edge{int u, v, w;};
vector<edge> edges;
int route[1145][10];
int dis[1145][1145];
int fa[1145];
int n, m, k = 0;
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void init(){
	for (int i = 1; i <= n; i++)fa[i] = i;
}
int find(int x){
	if (x == fa[x])return x;
	else return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int rtx = find(x), rty = find(y);
	if (rtx == rty)return;
	if (rtx > rty)swap(rtx, rty);
	fa[rty] = rtx;
}
int kruskal(){
	init();
    sort(edges.begin(), edges.end(), cmp);
    //printf("The size of edges is %lld. \n",edges.size());
    int cnt = 0, ans = 0;
    for (int i = 0; i < edges.size(); i++){
        if (cnt == n - 1)return ans;
        int u = edges[i].u, v = edges[i].v;
        if (find(u) == find(v))continue;
        //printf("Selected %lld -> %lld weighs %lld,",u,v,edges[i].w);
        //cout << vis[u] <<' ' << vis[v] << endl;
        ans += edges[i].w;
        merge(u, v);
        cnt++;
    }
    
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    // fare = 0;
    for (int i = 1, fare; i <= k; i++){
        scanf("%lld",&fare);
        for (int j = 1; j <= n; j++){
            scanf("%lld",&route[j][i]);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int minR = dis[i][j];
            for (int s = 1; s <= k; s++){
                minR = min(minR, route[i][s] + route[j][s]);
            }
            edges.push_back({i, j, minR});
            edges.push_back({j, i, minR});
        }
    }
    cout << kruskal();
	
}

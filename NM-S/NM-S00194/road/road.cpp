#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2e6 + 100;
const int MAXN = 1e3 + 100;
const int INF = 2e9;
struct node{
	int u,v,w;
}edge[MAXM];
long long dis[MAXN][MAXN];
long long val[MAXN];
int s[MAXN];
bool cmp(node x,node y){
	return x.w < y.w;
}
int find_set(int x){
	if(x != s[x]) return s[x] = find_set(s[x]);
	else return s[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
    	int u,v,w;
    	cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) dis[i][j] = INF;
	}
	for(int i = 1;i <= k;i++){
		int x;
		cin >> x;
		for(int j = 1;j <= n;j++) cin >> val[j];
		for(int j = 1;j <= n;j++){
			for(int k = j + 1;k <= n;k++) dis[j][k] = min(dis[j][k],val[j] + val[k] + x);
		}
	}
	int id = m;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			id++;
			edge[id].u = i;
			edge[id].v = j;
			edge[id].w = dis[i][j];
		}
	}
	for(int i = 1;i <= n;i++) s[i] = i;
	sort(edge + 1,edge + id + 1,cmp);
	int num = 0,ans = 0;
	for(int i = 1;i <= id;i++){
		node now = edge[i];
		int u = now.u;
		int v = now.v;
		int w = now.w;
		int s1 = find_set(u);
		int s2 = find_set(v);
		if(s1 != s2){
			s[s1] = s[s2];
			num++;
			ans += w;
		}
		if(num == n - 1) break;
	}
	cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

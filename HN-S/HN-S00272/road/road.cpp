#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll ans = 0;
int n, m, k, cs[20][N], c[N];
struct node{
	int v, w;
};
bool cmp(node x, node y){
	if(x.w < y.w) return true;
	return false;
}
vector<node> ve[N];
vector<node> v2[N];
int main(){
	freopen("road.in","r", stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		ve[u].push_back({v, w});
		ve[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i ++){
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j ++){
			scanf("%d", &cs[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++){
		int x= 1e9;
		//sort(ve[i].begin, ve[i].end, cmp);
		for(int j = 0; j < ve[i].size(); j ++){
			x = min(x, ve[i][j].w);
		}
		ans += x;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4+10;
const int M = 1e6+10;

struct Road{
	int u, v, w;
} road[M];

struct Node{
	int w=0, num=0, a[50], id;
}cost1[N];

bool cmp(const Road& a, const Road& b){
	return a.w<b.w;
}

bool cmp_(const Node& a, const Node& b){
	return a.w>b.w;
}

int pa[N], siz[N];

int findR(int x){
	if(pa[x]==x) return x;
	return pa[x] = findR(pa[x]);
}

void mergeE(int x, int y){
	int xr = findR(x), yr = findR(y);
	if(xr==yr) return;
	if(siz[xr]>siz[yr]) swap(xr, yr);
	pa[xr] = yr;
	siz[yr]+=siz[xr];
}

int n, m, k, road_[N][N], C[15];

int solve(){
	sort(road+1, road+m+1, cmp);
	int ans = 0, cnt = 0;
	for(int i=1;i<=m;i++){
		Road r = road[i];
		if(findR(r.u)==findR(r.v)) continue;
		mergeE(r.u, r.v);
		cnt++, ans+=r.w;
		cost1[r.u].w+=r.w, cost1[r.v].w+=r.w;
		cost1[r.u].a[++cost1[r.u].num] = r.v;
		cost1[r.v].a[++cost1[r.v].num] = r.u;
		cost1[r.u].id = r.u, cost1[r.v].id = r.v;
		if(cnt==n-1) break;
	}
	sort(cost1+1, cost1+n+1, cmp_);
	int cityid = 1;
	for(int i=1;i<=k;i++){
		int co = 0;
		for(int j=1;j<=cost1[cityid].num;j++) ans += road_[cost1[cityid].a[j]][cost1[cityid].id];
		if(C[i]+co<=cost1[cityid].w){
			ans -= cost1[cityid].w-co-C[i];
			for(int j=1;j<=cost1[cityid].num;j++) cost1[cost1[cityid].a[j]].w -= cost1[cityid].w;
			if((cityid++)>n) break;
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) pa[i] = i, siz[i] = 1;
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		road[i] = {u, v, w};
	}
	for(int i=1;i<=k;i++){
		cin >> C[i];
		for(int j=1;j<=n;j++){
			int w;
			cin >> w;
			road_[i][j] = w;
			road_[j][i] = w;
		}
	}
	cout << solve();
	
	return 0;
}

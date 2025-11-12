#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 50010;
struct node {
int to, w;
const operator < (const node &a) {
	return w < a.w;
}
};
bool vmp(node x, node y) {
	return x.w < y.w;
}
vector<node> vec[N];
int c[N], a[15][N];
bool pand[N];
struct edge{
	int w, v;
}shuz[N];
int cnt = 0, ans=0, ans1=INT_MAX,n,m,k;
void zuix(int x, int ci) {
	//cout << 111;
	if(ci > n) {
		return;
	}
	int ji, minw = LLONG_MAX;pand[x] = 1;
	bool duanjjk = 0;
	for(int i = 0;i < vec[x].size();i ++) {
		int v = vec[x][i].to;
		int w = vec[x][i].w;
		if(pand[v]) continue;
		shuz[++ cnt].w = w;
		shuz[cnt].v = v;
		duanjjk = 1;
	} int dddd = 0;
	if(duanjjk) {
		for(int i = 1;i <= cnt;i ++) {
			if(shuz[i].w < minw && !pand[shuz[i].v]) {
				minw = shuz[i].w;
				ji = shuz[i].v;	
				dddd = i;
			} 
		} 
		
		ans += shuz[dddd].w;
		shuz[dddd].w = LLONG_MAX;
		
		zuix(ji, ci ++);
	} 
	return;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++) {
		int u, v, w; cin >> u >> v >> w;
		vec[u].push_back({v, w});
		vec[v].push_back({u, w});
	} bool kp = 0;
	for(int i = 1;i <= k;i ++) {
		cin >> c[i];
		bool duan = 0;
		for(int j = 1;j <= n;j ++) {
			cin >> a[i][j];
			if(a[i][j] != 0) {
				duan = 1;
			}
		} if(!duan && c[i] == 0) kp = 1;
	}
	if(kp) {
		cout << 0 << endl;
	} else{
		zuix(1, 0);
		ans1 = min(ans1, ans);
		for(int i = 1;i <= k;i ++) {
			memset(pand, 0, sizeof(pand));
			ans = 0; cnt = 0;
			for(int j = 1;j <= n;j ++) {
				if(i == 1) vec[n + 1].push_back({j,a[i][j]});
				else vec[n + 1][j - 1].to = j, vec[n + 1][j - 1].w = a[i][j];
				vec[j].push_back({n+1,a[i][j]});
			} zuix(1,0);
			for(int j = 1;j <= n;j ++) {
				vec[j].pop_back();
			}ans1 = min(ans1, ans+c[i]);
		} 
		cout << ans1 << endl;
	}
	
	return 0;
} 

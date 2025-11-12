#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
long long d[maxn];
vector <pair<long long, int> > rd[maxn];//{w, v}
bool vis[maxn];
int n, m, k;
long long c[20];
long long rd2[20][maxn];


int zdl(int st){
	long long res = 0;
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
//	queue<int> q;
	pq.push({0, st});
	d[st] = 0;
	while (!pq.empty()){
		pair<long long, int> u = pq.top(); pq.pop();
//		cout << u.first << " " << u.second << '\n';
		if (vis[u.second])continue;
		res += d[u.second];
		vis[u.second] = true;
		for (auto v : rd[u.second]){
//			cout << "当前" << u.second << " 遍历到" << v.second << " 距离为" << v.first << " 两边和" << d[u.second] + v.first << " v的原距离" << d[v.second] << '\n';
			if (v.first < d[v.second]){
				d[v.second] = v.first;
				pq.push({d[v.second], v.second});
//				cout << "push了:"<< d[v.second] << " " << v.second<< "\n";
			}
		}
	}
	return res;
	
}

void solve(){
	cin >> n >> m >> k;
	int u, v, w;
	for (int i=1; i<=m; i++){
		cin >> u >> v >> w;
		rd[u].push_back({w, v});
		rd[v].push_back({w, u});
	}
	for (int i=1; i<=k; i++){
		cin >> c[i];
		for (int j=1; j<=n; j++){
			cin >> rd2[i][j];
		}
		for (int a=1; a<=n; a++){
			for (int b=a+1; b<=n; b++){
				rd[a].push_back({rd2[i][a] + rd2[i][b] + c[i], b});
				rd[b].push_back({rd2[i][a] + rd2[i][b] + c[i], a});
			}
		}
	}
//	cout << n << m << k << '\n';
//	for (int i=1; i<=k; i++){
//		for (int j=1; j<=n; j++){
//			cout << rd2[i][j] << " ";
//		}cout << endl;
//	}
//	for (int i=1; i<=n; i++){
//		cout << i << ": \n";
//		for (auto a : rd[i]){
//			cout << a.second << " " << a.first << "\n";
//		}
//	}
	cout << zdl(1);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}

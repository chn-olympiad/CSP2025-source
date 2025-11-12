#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const bool CHECK = 0, CHECK2 = 0;
const int K = 12, N = 1e4 + 5, M = 2e6 + 5;
const int _K = K + 1, _N = N + 5, _M = M + 5;
int c[_K], a[_K][_N];
bool ca[_K][_N];
int ieg, eghe[_N];
struct Eg {
	int u, v, w, nxt;
	friend bool operator < (Eg e1, Eg e2) {
		return e1.w > e2.w;
	}
} eg[_M];
priority_queue<Eg> pqe;
void adde(int u, int v, int w) {
	ieg++;
	eg[ieg].u = u;
	eg[ieg].v = v;
	eg[ieg].w = w;
	eg[ieg].nxt = eghe[u];
	eghe[u] = ieg;
}
struct Tg {
	int v, w;
	friend bool operator < (Tg t1, Tg t2) {
		return t1.w > t2.w;
	}
};
priority_queue<Tg> pqt[_K];
bool vist[_K], visp[_N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adde(u, v, w); adde(v, u, w);
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			Tg tmpg; tmpg.v = j; tmpg.w = a[i][j];
			pqt[i].push(tmpg);
		}
	}
	ll ans = 0;
	int cnta = 0, np = 1;
	visp[np] = 1;
	for(int i = eghe[np]; i; i = eg[i].nxt) {
		pqe.push(eg[i]);
	}
	if(CHECK) {
		cout << "STEP 1: " << endl;
		cout << "add point 1" << endl;
		cout << endl;
	}
	for(int cnta = 1; cnta < n; cnta++) {
		Eg mine = pqe.top();
		while(visp[mine.v]) {
			if(CHECK2) cout << "mine.v " << mine.v << endl;
			pqe.pop();
			mine = pqe.top();
		}
		ll mind = mine.w, minp = 0, mintg = 0, maxc = 0;
		for(int i = 1; i <= k; i++) {
			ll dis = 0;
			if(!ca[i][np]) dis += a[i][np];
			if(!vist[i]) dis += c[i];
			Tg ctg = pqt[i].top();
			while(visp[ctg.v]) {
				if(CHECK2) cout << "ctg.v " << ctg.v << endl;
				pqt[i].pop();
				ctg = pqt[i].top();
			}
			dis += ctg.w;
			if(dis <= mind && !vist[i] && c[i] + pqt[i].top().w >= maxc) {
				minp = i;
				mind = dis;
				mintg = ctg.v;
				maxc = c[i] + pqt[i].top().w;
			}
		}
		ans += mind;
		if(minp == 0) {
			np = mine.v;
			pqe.pop();
		} else {
			vist[minp] = 1;
			ca[minp][np] = 1;
			pqt[minp].pop();
			np = mintg;
		}
		visp[np] = 1;
		for(int i = eghe[np]; i; i = eg[i].nxt) {
			pqe.push(eg[i]);
		}
		if(CHECK) {
			cout << "STEP " << cnta + 1 << ": " << endl;
			cout << "add point " << np << endl;
			if(minp != 0) cout << "add town " << minp << endl;
			cout << "add dis " << mind << endl;
			cout << endl;
		}
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;
const ll mod = 998244353;

int T, n;
int a[N][4];
vector<int> v[4], vt;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++) cin >> a[i][j];
		}
		for (int i = 1; i <= 3; i++) v[i].clear();
		int ans = 0;
		for (int i = 1; i <= n; i++){
			pii pos = {0, 0};
			for (int j = 1; j <= 3; j++) pos = max(pos, {a[i][j], j});
			ans += pos.fir;
			v[pos.sec].push_back(i);
		}
		pii pos = {0, 0};
		for (int i = 1; i <= 3; i++) pos = max(pos, {v[i].size(), i});
		if (pos.fir <= n / 2) {cout << ans << "\n"; continue;}
		vt.clear();
		for (auto it : v[pos.sec]){
			int mn = inf;
			for (int i = 1; i <= 3; i++){
				if (i != pos.sec) mn = min(mn, a[it][pos.sec] - a[it][i]);
			}
			vt.push_back(mn);
		} 
		sort(vt.begin(), vt.end());
		for (int i = 0; i < pos.fir - n / 2; i++) ans -= vt[i];
		cout << ans << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 20, MAXM = (1 << 20);
const int MOD = 998244353;
int c[MAXN], p[MAXN];
string s;
int n, m, ans;
bool vis[MAXN];
void solve(int step){
	if (step > n){
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++){
			int u = p[i];
			if (cnt >= c[u] || s[i - 1] == '0'){
				cnt++;
			}
			else{
				res++;
			}
		}
		if (res >= m){
			ans++;
		}
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]){
			continue;
		}
		vis[i] = true;
		p[step] = i;
		solve(step + 1);
		vis[i] = false;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	solve(1);
	cout << ans << endl;
	return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 998244353;

int n, m, ans;
string s;
int c[505];
int p[505];

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m;
  cin >> s;
  for (int i = 1; i <= n; i++) {
  	cin >> c[i];
  	p[i] = i;
	}
	do {
		int cnt = 0, sum = 0;
		for (int i = 1; i <= n && sum < m; i++) {
			if (cnt >= c[p[i]]) {
				cnt++;
				continue;
			}
			if (s[i - 1] == '0')
				cnt++;
			else
				sum++;
		}
		if (sum >= m)
			ans = (ans + 1) % MOD;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << endl;
  return 0;
}



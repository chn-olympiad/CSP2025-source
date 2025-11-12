#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[505];
int c[505];
bool used[505];
int ans = 0;
void dfs(int k, vector<int> p)
{
	if(k == n) {
		int luyong = 0, jujue = 0;
		for (int i = 0; i < k; i++) {
			if (s[i] == '1' && jujue < c[p[i]]) {
				luyong++;
				if (luyong >= m) {
					ans++;
					return;
				}
			}
			else {
				jujue++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == false) {
			p.push_back(i);
			used[i] = true;
			dfs(++k, p);
			k--;
			used[i] = false;
			p.pop_back();
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dfs(0, {});
	cout << ans % 998244353;
	return 0;
}

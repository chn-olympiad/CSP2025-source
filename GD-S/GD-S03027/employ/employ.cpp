#include<bits/stdc++.h>
using namespace std;
const int N = 501, mod = 998244353;
int n, m, a[N], flag[N], num[N], sum, ans, rp;
string cc, s;
void dfs(int t) {
	if(t == n + 1) {
		sum = rp = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '1' && rp < a[num[i]]) {
				sum++;
			}
			else {
				rp++;
			}
		}
		if(sum >= m) {
			ans++;
		}
		return ;
	}
	else {
		for(int i = 1; i <= n; i++) {
			if(flag[i] == 0) {
				flag[i] = 1;
				num[t] = i;
				dfs(t + 1);
				flag[i] = 0;
			}
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> cc;
	for(int i = 0; i < n; i++) {
		s[i + 1] = cc[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}

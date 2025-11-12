#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int a[N], cnt, ans, n;
void dfs(int x, string s) {
	if(x>n) {
		int sum = 0, ji = 0, jiii = 0;
		//cout << s << endl;
		for(int i = 0;i < s.size();i ++) {
			if(s[i] == ' ') continue;
			if(s[i] == '0') continue;
			sum += a[i], ji ++, jiii = i;
		}
		if(sum > a[jiii] * 2 && ji >= 3) {
			ans ++;
		//	cout << s << endl;
		}
		return;
	}
	for(int i = 0;i <= 1;i ++) {
		char c = (char)(i + '0');
		dfs(x + 1, s + c);
	} return;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	dfs(1, " ");
	cout << ans;
	return 0;
} 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
//#include <cmath>
#include <cstdint>
#include <cstring>
using namespace std;
typedef pair <int, int> pii;
typedef pair <string, string> prs;
typedef int64_t i64;
const int N = 2e5 + 10; // 检查大小、空间

int n, q;
prs s[N], t[N];

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i].first >> s[i].second;
	for(int i = 1; i <= q; i++) cin >> t[i].first >> t[i].second;
	for(int i = 1; i <= q; i++) {
		string t0 = t[i].first, t1 = t[i].second;
		int ans = 0;
		for(int j = 1; j <= n; j++) {
			string s0 = s[j].first, s1 = s[j].second;
			for(int l = 0; l + s0.length() <= t0.length(); l++) {
				int r = l + s0.length() - 1; string ns;
				//cout << s0.length() << " " << l << " " << r << '\n';
				bool flag = 1;
				for(int i = 0; i < l && flag; i++) {
					if(t0[i] != t1[i]) flag = 0;
				}
				for(int i = l; i <= r && flag; i++) {
					if(t0[i] != s0[i - l] || s1[i - l] != t1[i]) flag = 0;
				}
				for(int i = r + 1; (i < t0.length()) && flag; i++) {
					if(t0[i] != t1[i]) flag = 0;
				}
				ans += flag;
			}
		}
		cout << ans << '\n';
	}
	return void(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); // 测试 freopen
	solve();
	return 0;
}
// 检查调试语句、i64、空间、时间、代码版本、freopen
// Think twice, code once.
// 注意 Win 和 Linux 双过
// rp++　!!!!!
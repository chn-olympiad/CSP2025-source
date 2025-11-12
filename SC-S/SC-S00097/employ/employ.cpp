#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
//#include <cmath>
#include <cstdint>
#include <cstring>
using namespace std;
typedef pair <int, int> pii;
typedef int64_t i64;
const int N = 3e5 + 10; // 检查大小、空间

int n, m, ans;
int hd[N], val[N], c[N];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		hd[i] = (ch == '1' ? 1 : 0);
		val[i] = i;
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	do {
		int cntq = 0, cntj = 0;
		for(int d = 1; d <= n; d++) {
			int i = val[d];
			if(cntq >= c[i] || !hd[d]) {
				cntq++;
				continue;
			}
			cntj++;
		}
		if(cntj >= m) ans++;
	} while(next_permutation(val + 1, val + n + 1));
	cout << ans << '\n';
	return void(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); // 测试 freopen
	solve();
	return 0;
}
// 检查调试语句、i64、空间、时间、代码版本、freopen
// Think twice, code once.
// 注意 Win 和 Linux 双过
// rp++　!!!!!
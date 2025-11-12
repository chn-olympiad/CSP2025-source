/*
   FJ-J02111
   FJ-S01838
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Node {
	int a, b, c;
	int tot;
};

constexpr int N = 1e5 + 2;
Node a[N];
//Node b[N];
//Node c[N];
int n;

bool cmp1(Node, Node);
bool cmp2(Node, Node);
bool cmp3(Node, Node);
bool cmp4(Node, Node);

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand(time(0));
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		bool FlagA = true, FlagB = true;
		int tmp = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].tot = a[i].a + a[i].b + a[i].c;
			if (a[i].b != 0 || a[i].c != 0) {
				FlagA = false;
			}
			if (a[i].c != 0) {
				FlagB = false;
			}
		}
		if (n == 2) { // 5pts
			cout << max({a[1].a + a[2].b, a[1].a + a[2].c,
			             a[1].b + a[2].a, a[1].b + a[2].c,
			             a[1].c + a[2].a, a[1].c + a[2].b
			            })
			     << "\n";
			continue;
		}
		if (FlagA) { //5pts
			sort(a + 1, a + n + 1, cmp1);
			int ans = 0;
			for (int i = 1; i <= tmp; i++) {
				ans += a[i].a;
			}
			cout << ans << "\n";
			continue;
		}
		if (FlagB) { //15pts
			sort(a + 1, a + n + 1, cmp4);
			int tmpA = 0, tmpB = 0;
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i].a == a[i].b) {
					if (tmpA < tmpB) {
						tmpA++;
					} else {
						tmpB++;
					}
					ans += a[i].a;
				} else if (a[i].a > a[i].b) {
					if (tmpA < tmp) {
						tmpA++;
						ans += a[i].a;
					} else {
						tmpB++;
						ans += a[i].b;
					}
				} else {
					if (tmpB < tmp) {
						tmpB++;
						ans += a[i].b;
					} else {
						tmpA++;
						ans += a[i].a;
					}
				}
			}
			cout << ans << "\n";
			continue; 
		}
//		mt19937 mt(time(0)); 
//		cout << mt() << "\n";
		cout << rand() << "\n"; 
//		for (int i = 1; i <= tmp; i++) {
//			for (int j = 1; j <= tmp; j++) {
//				for (int k = 1; k <= tmp; k++) {
//					dp[i][j][k] = dp[i][j][k - 1];
//				}
//			}
//		}
	}
	return 0;
}

bool cmp1(Node a, Node b) {
	return a.a > b.a;
}
bool cmp2(Node a, Node b) {
	return a.b > b.b;
}
bool cmp3(Node a, Node b) {
	return a.c > b.c;
}
bool cmp4(Node a, Node b) {
	return a.tot > b.tot;
}

/*
14:45
尝试暴力
15:03
考虑贪心
15:13
暴力假了（？？？），继续考虑贪心
15:26
贪心好像也假了
15:30
考虑 n=2
15:35
推倒重写
15:40
n=2 写出来了,不想写其他情况了，下一题
16:54
考虑DP
17:13
考虑随机数
17:16
考虑特殊性质A
17:20
考虑特殊性质B
17:35
答案位数正确也是正确，不调了 
*/


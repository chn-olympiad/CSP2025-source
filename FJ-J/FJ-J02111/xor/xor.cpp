#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int N = 5e5  +2;
int a[N];
int s[N];
int n, k;

int main()
{
	// RP++++++++++++++++++++++++++++++++++++++++
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] ^ s[i - 1];  // 前缀异或和 
	}
	int l = 1, r = 1;
	int ans = 0;
	int tmp = 0;
	while (l <= r && r <= n) {
//		cout << l << " " << r << "\n";
//		int tmp = s[r] ^ s[l - 1];
		tmp ^= a[r];
		if (tmp == k) {
//			cout << "----------------------------\n";
//			cout << l << " " << r << "\n";
			ans++;
			r++;
			l = r;
			tmp = 0;
		} else if (tmp > k) {
			tmp ^= a[l];
			l++;
			r++;
		} else {
			r++;
		}
	}
	cout << ans << "\n";
//	while(true);
	return 0;
}
/*
10:10 start 
10:20 
有点问题
尝试使用数组将所有异或和为 k 的区间都记录下来
但这真的不会爆掉吗（无论是时间上还是空间上）？？？？？ 
10:30
样例1~4莫名其妙地过了
这尺取写得跟shi一样 
不过特殊性质AB的分应该是有了
expect >=30pts 
11:05
tmd 还在调xor
懒得调了，去打暴力的T4吧 
*/


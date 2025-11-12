#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 500005;
int n, k, a[N], sum[N];
int lst[1 << 20], gt[N];
int R, cnt;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(lst, -1, sizeof(lst)); lst[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; sum[i] = sum[i - 1] ^ a[i];
		gt[i] = lst[sum[i] ^ k], lst[sum[i]] = i;
		if (gt[i] >= R) cnt++, R = i;
	} cout << cnt;
}

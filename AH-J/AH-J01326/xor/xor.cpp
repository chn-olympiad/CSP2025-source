#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 5;
int n, k, mx, cnt;
int a[500005], lst[N];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i], a[i] ^= a[i - 1];
	memset(lst, -1, sizeof(lst));
	lst[0] = 0;
	for(int i = 1; i <= n; i++) {
		int j = lst[a[i] ^ k];
		if(j >= mx) cnt++, mx = i;
		lst[a[i]] = i;
	}
	cout << cnt << endl;
	return 0;
}

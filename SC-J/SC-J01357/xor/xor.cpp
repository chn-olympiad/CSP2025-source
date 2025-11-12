#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int n, k, a[maxn], px[maxn], f[maxn], l[maxn];

map <int, int> last;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		px[i] = px[i - 1] ^ a[i];
		if(last[k ^ px[i]]) l[i] = last[k ^ px[i]] + 1;
		else if(px[i] == k) l[i] = 1;
		last[px[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if(l[i]) f[i] = max(f[i], f[l[i] - 1] + 1);
	}
	cout << f[n] << "\n";
	return 0;
}
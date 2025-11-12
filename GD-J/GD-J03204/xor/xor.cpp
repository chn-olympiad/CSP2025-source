#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e7 + 10;
int n, k, a[N], ans, t[N];
void dfs(int x, int c, int s) {
	if(x > n) {
		ans = max(ans, c);
		t[ans]++;
		if(t[ans] > 1) {
			cout << ans;
			exit(0);
		}
		return;
	}
	int num = int(a[x] ^ s);
	if((s == -1 && a[x] == k) || (num == k && s != -1)) dfs(x + 1, c + 1, -1);
	else {
		int p = (s == -1 ? a[x] : num);
		dfs(x + 1, c, p); dfs(x + 1, c, s);
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 0, -1);
	cout << ans;
	return 0;
} 

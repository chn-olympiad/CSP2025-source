#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e2 + 9;
int n, m, c[N];
char s[N];
ll ans = 1;

int main(){
	freopen("cmploy.in", "r", stdin);
	freopen("cmploy.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 2; i <= n; i++) ans *= i, ans %= 998244353;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

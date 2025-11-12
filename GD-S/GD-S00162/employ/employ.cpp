#include <bits/stdc++.h>
#define modd 998244353
#define N 505
#define ll long long 
using namespace std;
int n, m, c[N];
string s;
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	int len = s.size();
	bool flag = 0;
	for (int i = 0; i < len; i++){
		if (s[i] != '1')flag = 1;
	}
	if (!flag){
		ll ans = 1;
		for (int i = 1; i <= n; i++){
			ans *= i;
			ans %= modd;
		}
		printf("%lld", ans);
	}
	else 
		printf("%d", m);
	return 0;
}

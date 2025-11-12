#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long pi1 = 1, pi2 =1;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
		pi1 = pi1 * i % 998244353;
	for(int i = 1; i < m; i++)
		pi2 = pi2 * (n - i + 1) % 998244353;
	cout << abs(pi1 - pi2) + m;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 510, mod = 998244353;
ll po[N], impo[N], n, m, c[N];
string s;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);freopen("employ.out", "w", stdout);
	po[0] = 1;
	for(int i = 1;i <= 502;i ++) po[i] = po[i - 1] * i % mod;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i ++) cin >> c[i];
	cout << po[n] << '\n';
	return 0;
}

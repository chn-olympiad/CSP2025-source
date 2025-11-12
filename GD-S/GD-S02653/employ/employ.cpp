#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

const int MOD = 998244353;
char s[510];
int c[510], num[510];

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) num[i] = i;
	int ans = 0;
	do
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(cnt >= c[num[i]] || s[i] == '0') cnt++;
		if(n - cnt >= m) ans = (ans + 1) % MOD;
	}while(next_permutation(num + 1, num + n + 1));
	cout << ans << '\n';
	
	fclose(stdin); fclose(stdout);
	return 0;
}

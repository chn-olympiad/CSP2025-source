#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int maxn = 5e2 + 1;
int a[maxn], c[maxn], pre[maxn];
ll ans;
string s;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		a[i] = i;
		s[i - 1] == '1' ? pre[i] = pre[i - 1] + 1 : pre[i] = pre[i - 1];
		scanf("%d", &c[i]);
	}
	do
	{
		int ok = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i - 1 - ok >= c[a[i]])
			{
				continue;
			}
			if(ok + (pre[n] - pre[i - 1]) < m)
			{
				break;
			}
			if(s[i - 1] == '1')
			{
				ok++;
			}
		}
		if(ok >= m)
		{
			ans = (ans + 1) % mod;
		}
	}
	while(next_permutation(a + 1, a + n + 1));
	printf("%lld", ans);
	return 0;
}

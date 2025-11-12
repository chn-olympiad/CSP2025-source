#include <bits/stdc++.h>
#define int long long
const int MAXN = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
using namespace std;
int n, q;
string a[MAXN], b[MAXN];
string x, y;
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%lld%lld", &n, &q);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i] >> b[i];
	}
	while ( q-- )
	{
		int ans = 0;
		cin >> x >> y;
		for ( int i = 1; i <= n; i++ )
		{
			string ui = x;
			int pos = x.find(a[i]);
			if ( pos != -1 )
			{
				for ( size_t j = pos; j < pos + a[i].size(); j++ )
				{
					ui[j] = b[i][j - pos];
				}
				if ( ui == y )
				{
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

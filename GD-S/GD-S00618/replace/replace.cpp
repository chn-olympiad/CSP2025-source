#include <iostream>
#include <string>
using namespace std;
#define int unsigned long long

const int N = 1e3 + 10,BASE = 26;
int n,q,h[N][N],p[N][N],a[N],b[N],hpow[N],lener[N];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	hpow[0] = 1;
	for(int i = 1;i < N;i ++) hpow[i] = hpow[i - 1] * BASE;
	for(int i = 1;i <= n;i ++)
	{
		string x,y;
		cin >> x >> y;
		int m = x.size();
		for(int j = 0;j < m;j ++)
		a[i] = a[i] * BASE + x[j] - 'a' + 1;
		for(int j = 0;j < m;j ++) b[i] = b[i] * BASE + y[j] - 'a' + 1;
		lener[i] = m;
	}
	while (q --)
	{
		string x,y;
		cin >> x >> y;
		int m = x.size(),ans = 0;
		x = " " + x,y = " " + y;
		if (x.size() != y.size())
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 1;i <= m;i ++)
			for(int j = 1;i + j - 1 <= m;j ++)
				h[i][j] = h[i][j - 1] * BASE + x[i + j - 1] - 'a' + 1;
		for(int i = 1;i <= m;i ++)
			for(int j = 1;i + j - 1 <= m;j ++)
				p[i][j] = p[i][j - 1] * BASE + y[i + j - 1] - 'a' + 1;
		for(int i = 1;i <= m;i ++)
			for(int j = 1;j <= n;j ++)
			{
				int len = lener[j];
				if (i + len - 1 > m) continue;
				int h1 = h[1][i - 1],h2 = p[1][i - 1];
				if (h1 != h2) continue;
				h1 = h[i][len],h2 = p[i][len];
				if (h1 != a[j] || h2 != b[j]) continue;
				h1 = h[i + len][m - i - len + 1],h2 = p[i + len][m - i - len + 1];
				if (h1 != h2) continue;
				ans ++;
			}
		cout << ans << endl;
	}
	return 0;
}

/*
3 4
a b
b c
c d
aa bb

*/







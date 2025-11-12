#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2 * 1e5 + 10;
int n, q;
struct dic
{
	string x, y;
}a[N];
signed main ()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	scanf ("%lld %lld", &n, &q);
	for (int i = 1; i <= n; i ++)
		cin >> a[i].x >> a[i].y;
	while (q --)
	{
		string t1, t2;
		cin >> t1 >> t2;
		int l = t1.size ();
		int ans = 0; 
		for (int i = 1; i <= n; i ++)
		{
			if (t1.find (a[i].x) != -1 && t2.find (a[i].y) != -1)
			{
				string ts = t1, X, Z;
				int u = t1.find (a[i].x);
				int v = u + a[i].x.size ();
				for (int j = 0; j < u; j ++)
					X += t1[j];
				for (int j = v; j < l; j ++)
					Z += t1[j];
				if ((X + a[i].y + Z) == t2) ans ++;
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
//终于到第三题了 
//上一条代码我们讲到，打空格是因为破译校准，但其实各种交互也是空格
//而且你不觉得打空格很好看嘛
//114514 114514
//而且方便检查，很简洁 

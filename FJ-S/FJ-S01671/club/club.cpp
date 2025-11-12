#include <bits/stdc++.h>
using namespace std;
struct Note
{
	int a, b, c;
}aa[100005];
int T, n, maxx, a, b, c, f[205][205][205];
bool cmp(Note a, Note b)
{
	return a.c > b.c;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		maxx = 0;
		if (n <= 200)
		{
			memset(f, 0, sizeof(f));
			for (int i = 1;i <= n;i++)
			{
				cin >> a >> b >> c;
				for (int j = 0;j <= min(i, n / 2);j++)
					for (int k = 0;k <= min(i, n / 2);k++)
					{
						int l = i -  j - k;
						if (l < 0) break;
						if (l > n / 2) continue;
						if (j > 0)
							f[j][k][l] = max(f[j][k][l], f[j - 1][k][l] + a);
						if (k > 0)
							f[j][k][l] = max(f[j][k][l], f[j][k - 1][l] + b);
						if (l > 0)
							f[j][k][l] = max(f[j][k][l], f[j][k][l - 1] + c);
						maxx = max(maxx, f[j][k][l]);
					}
			}
			cout << maxx << endl;
		}
		else
		{
			for (int i = 1;i <= n;i++)
			{
				cin >> aa[i].a >> aa[i].b >> aa[i].c;
				aa[i].c = aa[i].a - aa[i].b;
			}
			sort(aa + 1, aa + n + 1, cmp);
			for (int i = 1;i <= n / 2;i++) maxx += aa[i].a;
			for (int i = n / 2 + 1;i <= n;i++) maxx += aa[i].b;
			cout << maxx << endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct abc {
	int bumen;
	int myd;
}tmp;

int tmp0;

bool bmp (int x,int y)
{
	return x > y;
}

int t;
int n;
int ans;

int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		int a[n + 1][4];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		vector<abc> best;
		vector<int> work;
		int bm1 = 0,bm2 = 0,bm3 = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = a[i][1],y = a[i][2],z = a[i][3];
			if (x >= y && x >= z) {
				tmp.bumen = 1;
				tmp.myd = x;
				bm1++;
			}
			else {
				if (y >= x && y >= z) {
					tmp.bumen = 2;
					tmp.myd = y;
					bm2++;
				}
				else {
					tmp.bumen = 3;
					tmp.myd = z;
					bm3++;
				}
			}
			best.push_back(tmp);
		}
		if (bm1 <= n / 2 && bm2 <= n / 2 && bm3 <= n / 2)
		{
			for (int i = 0; i < best.size(); i++)
				ans += best[i].myd;
			cout << ans << endl;
			continue;
		}
		if (bm1 > n / 2)
		{
			for (int i = 0; i < best.size(); i++) {
				ans += best[i].myd;
				if (best[i].bumen != 1)
					continue;
				tmp0 = max(a[i + 1][2],a[i + 1][3]) - a[i + 1][1];
				work.push_back(tmp0);
			}
			sort (work.begin(),work.end(),bmp);
			for (int i = 0; i < bm1 - (n / 2); i++)
			{
				ans += work[i];
			}
		}
		if (bm2 > n / 2)
		{
			for (int i = 0; i < best.size(); i++) {
				ans += best[i].myd;
				if (best[i].bumen != 2)
					continue;
				tmp0 = max(a[i + 1][1],a[i + 1][3]) - a[i + 1][2];
				work.push_back(tmp0);
			}
			sort (work.begin(),work.end(),bmp);
			for (int i = 0; i < bm2 - (n / 2); i++)
			{
				ans += work[i];
			}
		}
		if (bm3 > n / 2)
		{
			for (int i = 0; i < best.size(); i++) {
				ans += best[i].myd;
				if (best[i].bumen != 3)
					continue;
				tmp0 = max(a[i + 1][2],a[i + 1][1]) - a[i + 1][3];
				work.push_back(tmp0);
			}
			sort (work.begin(),work.end(),bmp);
			for (int i = 0; i < bm3 - (n / 2); i++)
			{
				ans += work[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct P
{
	int a, b, c;
};

const int N = 1e5 + 10;
P a[N];
int t;

int main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		int n = 0, aa = 0, bb = 0, cc = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			int cnt = max(a[i].a, max(a[i].b, a[i].c));
			if (cnt == a[i].a && aa < n / 2)
			{
				aa++;
				continue; 
			}
			if (cnt == a[i].b && bb < n / 2)
			{
				bb++;
				continue; 
			}
			if (cnt == a[i].c && cc < n / 2)
			{
				cc++;
				continue; 
			}
		}
		cout << aa + bb + cc << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int t, n, a[N], b[N], c[N];
int na, nb, nc;
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--)
	{
		int x, y, z;
		ll sum = 0;
		na = nb = nc = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> x >> y >> z;
			int t = max(x, max(y, z));
			sum = sum + t;
			if(x == t) a[++na] = min(x - y, x - z);
			else if(y == t) b[++nb] = min(y - x, y - z);
			else if(z == t) c[++nc] = min(z - x, z - y);
		}
		int hf = (n >> 1);
		if(na > hf)
		{
			sort(a + 1, a + na + 1);
			for(int i = 1; i <= na - hf; i++) sum = sum - a[i];
		}
		else if(nb > hf)
		{
			sort(b + 1, b + nb + 1);
			for(int i = 1; i <= nb - hf; i++) sum = sum - b[i];
		}
		else if(nc > hf)
		{
			sort(c + 1, c + nc + 1);
			for(int i = 1; i <= nc - hf; i++) sum = sum - c[i];
		}
		cout << sum << '\n';
	}
	return 0;
}
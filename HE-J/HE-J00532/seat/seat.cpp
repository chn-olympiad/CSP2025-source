#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
void solve()
{
	cin >> n >> m;
	int cnt = 0,res = 1,sum = 0;
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1,x;j <= m;++j)
		{
			cin >> x;
			if(i == 1 && j == 1) sum = x;
			else if(x > sum) ++ res;
		}
	}
	int p = res % n;
	int q = res / n;
//	cout << p << q << '\n';
	if(p == 0)
	{
		if(q & 1) cout << q << ' ' << n << '\n';
		else cout << q << ' ' << 1 << '\n';
	}
	else
	{
		if(q & 1) cout << q + 1 << ' ' << n - p + 1 << '\n';
		else cout << q + 1 << ' ' << p << '\n';
	}
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
}

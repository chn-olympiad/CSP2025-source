#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+6;
int a[N] = {};
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,t;
	cin >> n >> t;
	int h = 0;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i] == t)
		{
			h = i;
		}
	}
	if (h != 0)cout << 1;
	else cout << 2;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define mod 958244353

const int N = 5E3 + 10;
int n, m;
long long tot;
string s;
int a[N], b[N];

void dfs(int step, int pos)
{
	if (step > pos)
	{
		tot = (tot + 1) % mod;
	}
	else
	{
		for (int i = b[step - 1] + 1; i <= n; ++i)
		{
			b[step] = i;
			dfs(step + 1, pos);
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dfs(1, m);
	cout << tot << '\n';
	return 0;
}


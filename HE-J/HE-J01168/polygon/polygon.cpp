#include <bits/stdc++.h>
using namespace std;
#define mod 998244353;

const int N = 5e5 + 10;
int n;
int a[N], b[N];
long long tot;

void dfs(int step, int pos)
{
	if (step > pos)
	{
		long long arr = a[b[pos]];
		long long num = 0;
		for (int i = 1; i <= pos; ++i) num = (num + a[b[i]]);
		if (num > arr * 2) tot = (tot + 1) % mod;
		return ;
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
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for (int i = 3; i <= n; ++i)
	{
		for (int j = 1; j <= n + 5; ++j) b[j] = 0;
		dfs(1, i);
	}
	
	cout << tot << '\n';
	
	return 0;
}

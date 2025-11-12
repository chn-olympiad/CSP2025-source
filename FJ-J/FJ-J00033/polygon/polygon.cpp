#include<bits/stdc++.h>
using namespace std;
int n, a[5001], b[5002], c[5002], maxx, s, t;
void dfs(int p, int q)
{
	if(p > n)
		return;
	if(q >= 3 && t > 2 * maxx)
		s++;
	dfs(p + 1, q);
	t += a[p], maxx = max(a[p], maxx);
	int b = maxx;
	dfs(p + 1, q + 1);
	t -= a[p], maxx = b;
	return;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(0, 0), cout << s;
	
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
int n, k, a[500005], t;
int dfs(int l, int r, int sum, int jsq, int f)
{
	if (sum==k)
	{
		jsq++;
	}
	if (l==r)
	{
		return jsq;
	}
	f=dfs(l, r-1, sum^a[r], 0, 0)+dfs(r, r, a[r], 0, 0);
	f=max(dfs(l+1, r, sum^a[l], 0, 0)+dfs(l, l, a[l], 0, 0), f);
	jsq=max(f, jsq);
	return jsq;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		t=t&a[i];
	}
	cout << dfs(1, n, t, 0, 0);
	return 0;
}

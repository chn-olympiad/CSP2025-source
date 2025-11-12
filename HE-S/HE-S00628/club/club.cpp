#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int t,n,a[maxn],b[maxn],c[maxn];

int dfs(int x, int A, int B, int C)
{
	int ansa = 0,ansb = 0,ansc = 0;
	if (x == n)
	{
		if (A < n/2) ansa = a[x];
		if (B < n/2) ansb = b[x];
		if (C < n/2) ansc = c[x];
		return max(ansa,max(ansb,ansc));
	}
	if (A < n/2) ansa = a[x]+dfs(x+1,A+1,B,C);
	if (B < n/2) ansb = b[x]+dfs(x+1,A,B+1,C);
	if (C < n/2) ansc = c[x]+dfs(x+1,A,B,C+1);
	return max(ansa,max(ansb,ansc));
}

bool cmp(int x, int y)
{
	return x > y;
}

int dfs2(int x, int A, int B)
{
	int ansa = 0,ansb = 0;
	if (x == n)
	{
		if (A < n/2) ansa = a[x];
		if (B < n/2) ansb = b[x];
		return max(ansa,ansb);
	}
	if (A < n/2) ansa = a[x]+dfs2(x+1,A+1,B);
	if (B < n/2) ansb = b[x]+dfs2(x+1,A,B+1);
	return max(ansa,ansb);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i] >> b[i] >> c[i];
		int flag = 2;
		for (int i = 1; i <= n; i++)
			if (c[i] != 0 || b[i] != 0) flag = 1;
		for (int i = 1; i <= n; i++)
			if (c[i] != 0) flag = 0;
		if (flag == 2)
		{
			sort(a+1,a+n+1,cmp);
			for (int i = 1; i <= n/2; i++) ans += a[i];
			cout << ans << endl;
		}
		else if (flag == 1)
		{
			cout << dfs2(1,0,0) << endl;
		}
		else cout << dfs(1,0,0,0) << endl;
	}
	return 0;
}

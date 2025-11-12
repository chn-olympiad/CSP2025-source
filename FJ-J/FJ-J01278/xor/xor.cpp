#include<bits/stdc++.h>
using namespace std;
int n, k, a[500010], l, c[500010], ans, maxx = INT_MIN;
struct cnm
{
	int x, y;
}s[500010];
int cmp(cnm a, cnm b)
{
	return a.x < b.x;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) 
	{
		int ans = 0, op = 0;
		for(int j = i; j <= n; j++)
		{
			ans ^= a[j];
			op ^= a[j];
			if(ans == k || op == k)
			{
				s[++l].x = i;
				s[l].y = j;
				ans = 1;
			}
		}
	}
	sort(s + 1, s + l + 1, cmp);
	for(int i = 1; i <= l; i++)
	{
		int a1 = s[i].x, b1 = s[i].y;
		ans = 0;
		for(int j = 1; j <= l; j++)
		{
			if(b1 < s[j].x) a1 = s[j].x, b1 = s[j].y, ans++;
		}
		maxx = max(maxx, ans);
	}
	cout << maxx + 1;
	return 0;
}


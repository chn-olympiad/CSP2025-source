#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n;
int ans = 0;
int a[N];
void dfs(int now, int mx, int tot)
{
	if (tot > mx * 2) ans++;
	if (now == n + 1) return ;
	for(int i = now + 1; i <= n; i++)
	{
		dfs(i, max(mx, a[i]), tot + a[i]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w", stdout);
	cin >>n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int a[5005];
int n, ans=0;

void dfs(int srt, int dep, int num, int maxn)
{
	for(int i = srt + 1; i <= n; i++)
	{
		dfs(i, dep+1, num+a[i], a[i]);
	}
	if(num > maxn*2 && dep>=3)
	{
		ans++;
	}
	ans %= 998244353;
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		dfs(i, 1, a[i], a[i]);
	}
	cout << ans << endl;
	return 0;
}

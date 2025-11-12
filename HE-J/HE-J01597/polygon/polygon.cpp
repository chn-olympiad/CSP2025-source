#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5010;
const ll mod = 998244353;
int n;
int a[N];
int vis[N];
ll ans;
void dfs(int x,int Maxn,int sum)
{
	Maxn = max(Maxn,a[x]);
	if (x == n+1 && sum > 2*Maxn)
	{
		ans++;
		ans %= mod;
		return ;
	}
	vis[x] = 1;
	sum += a[x];
	dfs(x+1,Maxn,sum);
	vis[x] = 0;
	sum -= a[x];
	dfs(x+1,Maxn,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(1,INT_MIN,0);
	cout << ans;
	return 0;
}

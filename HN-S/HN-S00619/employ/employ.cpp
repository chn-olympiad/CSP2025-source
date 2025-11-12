#include<iostream>
using namespace std;
int n,m;
int stay[503];
bool used[503],speciala = 1,specialb;
long long ans;
string x;
void dfs(int now,int get,int quit)
{
	if(now >= n)
	{
		if(get >= m) ans++;
		ans %= 998244353;
		return;
	}
	if(n - quit + get < m) return;
	for(int i = 1;i <= n;i++)
	{
		if(used[i]) continue;
		used[i] = 1;
		if(stay[i] <= quit || x[now] == '0') dfs(now + 1,get,quit + 1);
		else dfs(now + 1,get + 1,quit);
		used[i] = 0;
	}
	return;
}
long long frac(long long now)
{
	long long x = 1;
	for(int i = 1;i <= now;i++)
	{
		x *= i;
		x %= 998244353;
	}
	return x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> x;
	for(auto i : x)
	{
		if(i == '0')
		{
			speciala = 0;
			break;
		}
	}
	for(int i = 1;i <= n;i++) cin >> stay[i];
	if(speciala)
	{
		for(int i = 1;i <= n;i++) if(stay[i]) ans++;
		if(ans < m) cout << 0;
		else cout << frac(n);
		return 0;
	}
	dfs(0,0,0);
	cout << ans;
}

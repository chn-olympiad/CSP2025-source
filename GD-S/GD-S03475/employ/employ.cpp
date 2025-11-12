#include <iostream>
using namespace std;
#define ll long long
const int N = 505;
const int P = 998244353;
int p[N];
string s;
int n,m;
int c[N];
bool check()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int h = p[i];
		if (cnt >= c[h]) cnt++;
		else if (s[i-1] == '0') cnt++;
	}
	return (n-cnt) >= m;
}
int ans;
bool vis[N];
void dfs(int stp)
{
	if (stp > n)
	{
		if (check()) ans++;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		p[stp] = i;
		dfs(stp+1);
		vis[i] = 0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	bool flaga = 1;
	for (char ch : s) if (ch != '1')
	{
		flaga = 0;
		break;
	}
	if (flaga)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (c[i] == 0) cnt++;
		cnt = n-cnt;
		if (cnt < m) cout << 0;
		else
		{
			ll lst = 1, now = 1;
			for (int i = 1; i <= n; i++)
			{
				now = (lst*i)%P;
				lst = now;
			}
			cout << now;
		}
		return 0;
	}
	dfs(1);
	cout << ans%P;
	return 0;
}

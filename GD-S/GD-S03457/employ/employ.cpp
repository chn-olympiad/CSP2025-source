#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, c[15], p[15], ans = 0;
string s;
bool vis[15];
bool chk()
{
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt >= c[p[i]] || s[i - 1] == '0')
		{
			cnt++;
		}
	}
	return n - cnt >= m;
}
void srh(int x)
{
	if(x > n)
	{
		ans += chk();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			p[x] = i;
			srh(x + 1);
			p[x] = 0;
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	srh(1);
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int c[505],ans[505],tmp,cnt,n,m,pfc;
bool s[505],vis[505];
void dfs(int cur)
{
	if (cur > n)
	{
		if (n - tmp >= m) cnt++;
		//cout << endl;
		return;	
	}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i]) continue;
		vis[i] = true;
		if (tmp >= c[i] || s[cur]) tmp++;
		//cout << "i:" << i << " tmp:" << tmp << " " << s[i] << " ";
		dfs(cur + 1);
		vis[i] = false;
		if (tmp > c[i] || s[cur]) tmp--;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string x;
	bool pf = true;
	cin >> n >> m >> x;
	for (int i = 0;i < x.size();i++) 
	{
		if (x[i] == '0') s[i + 1] = true;
	}
	for (int i = 1;i <= n;i++) 
	{
		cin >> c[i];
	}
	dfs(1);
	cout << cnt;
	return 0;
}

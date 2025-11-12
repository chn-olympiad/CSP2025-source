#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,p[505],c[505],ans;
bool vis[505];
string s;
void dfs(int k,int no)
{
	if(no > n-m) return;
	if(k == n+1)
	{
		ans++;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			if(c[i] <= no || s[k] == '0') dfs(k+1,no+1);
			else dfs(k+1,no);
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	s = " "+s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	dfs(1,0);
	cout << ans;
	return 0;
}


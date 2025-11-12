#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[505],mul = 1,ans[10000][15],cur,cnt,flag[15],tmp[15];
string s;
const ll mod = 998244353;
void dfs(int step)
{
	if (step > n)
	{
		cur ++;
		for (int i = 1;i<=n;i++)
		{
			ans[cur][i] = tmp[i];
		}
		return;
	}
	for (int i = 1;i<=n;i++)
	{
		if (flag[i]) continue;
		tmp[step] = i;
		flag[i] = 1;
		dfs(step + 1);
		flag[i] = 0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s = '?' + s;
	for (int i = 1;i<=n;i++) cin>>c[i];
	if (flag){ 
	for (int i = n;i>=1;i--)
	{
		mul *= i;
		mul %= mod;
	}
	cout<<mul<<endl;
	return 0;
}
	cout<<0<<endl;
	return 0;	
} 

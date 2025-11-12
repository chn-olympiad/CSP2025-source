#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 , Mod = 998244353;
int n,m,s[N+10],c[N+10],ans;
string zq;

int p[N+10],f[N+10];
void dfs(int x)
{
	if(x == n+1)
	{
		int rout = 0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(rout >= c[p[i]] || s[i] == 0)
				rout++;
			else
				cnt++;
		}
		if(cnt >= m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
			continue;
		f[i] = 1;
		p[x] = i;
		dfs(x+1);
		f[i] = 0;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m>>zq;
	
	for(int i=0;i<zq.size();i++)
		s[i+1] = zq[i]-'0';
	
	for(int i=1;i<=n;i++)
		cin>>c[i];
		
	dfs(1);
		
	cout<<ans;
	return 0;
} 

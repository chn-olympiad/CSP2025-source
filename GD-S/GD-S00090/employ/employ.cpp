#include<bits/stdc++.h>
using namespace std;
//#define int long long <----------------------
int n,m;
bool s[501];
int a[501];
int b[501];
bool vis[501];
int ans;
const int mod=998244353;
void dfs(int x)
{
	if(x>n)
	{
		int q=0;
		int f=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
			{
				q++; continue;
			}
			if(q>=b[i]) 
			{
				q++; continue;
			}
			f++;
		}
		if(f>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			b[x]=a[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x; cin>>x;
		if(x=='1') s[i]=1;
		else s[i]=0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*

shen shou bao you

*/

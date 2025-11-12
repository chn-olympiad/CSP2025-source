#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int N=2e5+114;
int n,m,a[N],c[N],b[N],flag[N],ans;
void dfs(int u)
{
	if(u==n+1)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0 || c[b[i]]<=cnt)cnt++;
			else sum++;
		}
		if(sum>=m)ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			b[u]=i;
			dfs(u+1);
			b[u]=0;
			flag[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)b[i]=i;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
这次比赛可能连100分都上不了。。。。。。

我已经尽力了哈哈哈（差点哭出来）

不过没关系，明年再接再厉，加油！！！
*/
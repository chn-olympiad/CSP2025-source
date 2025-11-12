#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,n,m,a[1000005];
bool bj[1000005];
char z[1000005];
void dfs(int x,int y)
{
	if(x==n+1)
	{
		if(n-y>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0)
		{
			bj[i]=1;
			if(z[x]=='0'||y>=a[i]) dfs(1+x,1+y);
			else dfs(1+x,y);
			bj[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>z;
	int flg=1,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(z[i]=='0') flg=0;
	}
	for(int i=n;i>=1;i--) z[i]=z[i-1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	if(flg)
	{
		int s=1;
		for(int i=1;i<=n-cnt;i++)
		{
			s*=i;
			s%=998244353;
		}
		cout<<s;
		return 0;
	}
	dfs(1,0);
	cout<<ans%998244353;
}

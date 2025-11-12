//GZ-S00440 贵阳市第十八中学 邹浚哲 
#include<bits/stdc++.h>
using namespace std;
const int N=501,mod=998244353;
int n,m,c[N],a[N];
long long ans=0;
char s[N];
bool vis[N];
void dfs(int u)
{
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			a[u]=i;
			if(u==n)
			{
				int cnt=0;
				for(int j=1;j<=n;j++)
					if(cnt>=c[a[j]]||s[j]=='0')
						cnt++;
				if(n-cnt>=m)
					ans=(ans+1)%mod;
			}
			else
				dfs(u+1);
			vis[i]=0;
		}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

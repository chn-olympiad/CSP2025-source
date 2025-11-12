//GZ-S00136 遵义市第四中学 安睿峰 
#include <bits/stdc++.h>
using namespace std;
int n,m,s[510],c[510],num,bo[510];
char a[510];
long long ans,mod=998244353;
void dfs(int d,int l)
{
	if(d==n+1)
	{
		if(n-l>=m)  ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(bo[i]==0)
		{
			bo[i]=1;
			if(l>=c[i]||s[d]==0)  dfs(d+1,l+1);
			else  dfs(d+1,l);
			bo[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=0;i<n;i++)  s[i+1]=a[i]-'0',num+=a[i+1];
	for(int i=1;i<=n;i++)  cin>>c[i];
	if(num<m){cout<<0;return 0;}
	dfs(1,0);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[514],b[514];
long long ans,sum;
string s;
const long long mod=998244353;
void dfs(int x,int l,int d)
{
	if(d>n) 
	{
		if(x>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(l>=a[i]&&!b[i]) 
		{
			b[i]=1;
			dfs(x,l+1,d+1);
			b[i]=0;
		}
		if(l<a[i]&&!b[i])
		{
			b[i]=1;
			if(s[d]=='1') dfs(x+1,l,d+1);
			else dfs(x,l+1,d+1);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0') p=1;
	s=" "+s; 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(0,0,1);
	printf("%lld",ans);
	return 0;
}

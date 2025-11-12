#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c[10005],b[10005];
ll ans;
const int mod=998244353;
string s;
void dfs(int x,int f)
{
	if(x>n)
	{
		if(n-f>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]) continue;
		b[i]=1;
		if(c[i]<=f||s[x-1]=='0') dfs(x+1,f+1);
		else dfs(x+1,f);
		b[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

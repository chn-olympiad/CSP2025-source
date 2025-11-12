#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,mod=998244353;
long long c[5001][5001];
void dg(int x,int y,int s,int mx)
{
	if(x>n)
	{
		if(y>=3&&s>2*mx) ans=(ans+1)%mod;
		return;
	}
	dg(x+1,y+1,s+a[x],a[x]);
	dg(x+1,y,s,mx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=5000;i++) c[i][i]=c[i][0]=1;
	for(int i=1;i<=5000;i++)
	for(int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n>26)
	{
		for(int i=3;i<=n;i++) ans=(ans+c[n][i])%mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dg(1,0,0,0);
	cout<<ans;
	return 0;
}

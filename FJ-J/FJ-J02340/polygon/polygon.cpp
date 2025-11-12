#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
#define lli long long
lli a[50015],ans,n,sum=0;
lli s[50015];
static const unsigned lli mod=998244353;
void dfs(int sum,int mx,int flg)
{
	if(flg>n)return;
	if(sum>2*mx&&flg>=3)ans=(ans+1)%mod;
	for(int i=flg+1;i<=n;i++)
	{
		//if(s[n]-s[i-1]+sum>2*mx)
		dfs(sum+a[i],max(1ll*mx,a[i]),i);
	}
		
}
lli c[5005][5005];
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flg=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i],flg=flg&&(a[i]==a[i-1]||i==1);
	if(flg==1)
	{
		for(int i=0;i<=n;i++)
			c[i][i]=1,c[0][i]=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				c[i][j]=(c[i-1][j-1]+c[i][j-1])%mod;
		for(int i=3;i<=n;i++)
			sum=(sum+c[i][n])%mod;
		cout<<sum;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,x,p,a[1005],b[1005],s[1005],ss[1005],f[1005],dp[105000][22][22],_dp[505][505],mod=998244353;
char c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m,f[0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]*i%mod;
	for(int i=1;i<=n;i++)cin>>c,b[i]=(c=='1'),s[i]=s[i-1]+b[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ss[a[i]]++;
	for(int i=1;i<=n;i++)ss[i]+=ss[i-1];
	if(n<=18){
		dp[0][0][0]=1;
		for(int i=0;i<(1<<n);i++)
			for(int j=0;j<n;j++)
				if(i&(1<<j)){
					x=i,p=0;
					while(x)x&=x-1,p++;
					for(int k=0;k<=p;k++){
						if(a[j+1]>k&&b[p]==1)dp[i][k][p]=(dp[i][k][p]+dp[i^(1<<j)][k][p-1])%mod;
						else if(a[j+1]<k||(b[p]==0&&k>0))dp[i][k][p]=(dp[i][k][p]+dp[i^(1<<j)][k-1][p-1])%mod;
					}
				}
		for(int i=0;i<=n-m;i++)ans=(ans+dp[(1<<n)-1][i][n])%mod;
		cout<<ans;
		return 0;
	}
	if(m==n)cout<<(ss[n]==n&&a[1]>0?f[n]:0);
	else cout<<0;
	return 0;
}


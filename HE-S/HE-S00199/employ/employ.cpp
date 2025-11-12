#include<bits/stdc++.h>
using namespace std;
long long dp[505][505],n,m,s[505],las,c[505],jc[505],sum[505],ans,cnt,sum0[505];
string ss;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;
	for(int i=1;i<=n;i++)cin>>c[i],sum[c[i]]++;
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%998244353;
	//for(int i=1;i<=n;i++)cout<<jc[i]<<" ";
	dp[0][0]=1;
	for(int i=1;i<=n;i++)if(ss[i-1]=='0')sum0[i]++;
	for(int i=1;i<=n;i++)sum0[i]+=sum0[i-1];
	for(int i=1;i<=n;i++){
		if(ss[i-1]=='0')continue;
		//cout<<i<<":";
		for(int j=sum0[i]+1;j<=i;j++)
		{
			if(j-(i-las-1)-1>=0)dp[i][j]=dp[las][j-(i-las-1)-1]*(sum[j-1]-(j-(i-las-1)-1)+sum0[las])%998244353;
			if(j-(i-las-1)>=0)dp[i][j]=(dp[i][j]+dp[las][j-(i-las-1)])%998244353;
			dp[i][j]%=998244353;
			//cout<<dp[i][j]<<" ";
		}
		//cout<<"last:"<<las<<endl;
		if(ss[i-1]=='1')las=i; 
	}
	for(int i=1;i<=las;i++)if(ss[i-1]=='0')cnt++;
	//cout<<cnt<<endl;
	for(int j=cnt;j<=n;j++)dp[las][j]=dp[las][j]*jc[n-j+cnt]%998244353;
	for(int j=n;j>n-m;j--)ans=(ans+dp[las][j])%998244353;
	cout<<(jc[n]+998244353-dp[las][n-m+1])%998244353;
	//cout<<endl<<jc[n]<<endl<<ans;
	return 0;
} 

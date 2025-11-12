#include<bits/stdc++.h>
#define ll long long 
#define M 998244353
using namespace std;
ll dp[3][510][510];//第i天，j人放弃，k人反选 
int c[510],cnc[510];
ll fct[510];
int sms[510];
char s[510];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		sms[i]=sms[i-1];
		if(s[i]=='0') sms[i]++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		cnc[c[i]]++;
	}
	for(int i=1;i<=n;i++) cnc[i]+=cnc[i-1];
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i+1;j++){
			for(int k=0;k<=i+1;k++) dp[1-i%2][j][k]=0;
		}
		if(s[i+1]=='0'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++) dp[1-i%2][j+1][k]=dp[i%2][j][k];
			}
		}
		else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					dp[1-i%2][j][k]=(dp[1-i%2][j][k]+dp[i%2][j][k])%M;
					dp[1-i%2][j+1][k]=(dp[1-i%2][j+1][k]+dp[i%2][j][k]*(cnc[j]-j+sms[i]-k)%M)%M;
					dp[1-i%2][j][k+1]=(dp[1-i%2][j][k+1]+dp[i%2][j][k]*(cnc[j]-j+sms[i]-k)%M)%M;
				}
			}
		}
//		for(int j=0;j<=i+1;j++){
//			for(int k=0;k<=i+1;k++){
//				if(dp[1-i%2][j][k]>0) printf("  %d %d %d  %lld\n",i+1,j,k,dp[1-i%2][j][k]);
//			}
//		}
	}
	fct[0]=1;
	for(int i=1;i<=n;i++) fct[i]=fct[i-1]*i%M;
	ll ans=0;
	for(int i=n-m;i<=n-m;i++){
		for(int j=0;j+i-sms[n]<=n;j++){
			if(j%2==0) ans=(ans+dp[n%2][i][j]*fct[n-i-j+sms[n]+sms[n]]%M)%M;
			else ans=(ans+M-dp[n%2][i][j]*fct[n-i-j+sms[n]+sms[n]]%M)%M;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

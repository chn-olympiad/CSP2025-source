#include<bits/stdc++.h>
using namespace std;
const int Maxn=502,Mod=998244353;
int n,m,dp[Maxn][Maxn][Maxn],bot[Maxn],ans;
char s[Maxn];
void Add(int &a,int b){a+=b;if (a>=Mod) a-=Mod;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1,c;i<=n;++i){scanf("%d",&c);++bot[c];}
	for(int i=n;i;--i) bot[i]+=bot[i+1];
	for(int i=m;i<=n;++i){
		dp[0][m][i]=1;
		for(int j=1;j<=n-i;++j) dp[0][m][i]=1ll*dp[0][m][i]*j%Mod;
		if ((i-m)&1) dp[0][m][i]=Mod-dp[0][m][i];
	}
	for(int i=1;i<=n;++i){
		if (s[i]=='1'){
			for(int j=1;j<=m;++j) for(int k=j;k<=n;++k){
				Add(dp[i][j][k],dp[i-1][j][k]);
				int c=max(i+j-m,0);
				if (bot[c]>k-1){
					Add(dp[i][j-1][k-1],1ll*dp[i-1][j][k]*(bot[c]-(k-1))%Mod);
					Add(dp[i][j][k-1],1ll*dp[i-1][j][k]*(bot[c]-(k-1))%Mod);
				}
			}
			Add(ans,dp[i][0][0]);
		}
		else{
			for(int j=1;j<=m;++j) for(int k=j;k<=n;++k) dp[i][j][k]=dp[i-1][j][k];
		}
	}
	printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353LL;
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int lent,val[5010];
int dp[10010][5],ret;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	lent=read();
	for(int i=1;i<=lent;i+=1){
		val[i]=read();
	}
	sort(val+1,val+lent+1);
	for(int i=1;i<=lent;i+=1){
		for(int j=10001;j>=0;j-=1){
			int k=min(j+val[i],10001LL);
		    if(k>val[i]*2){
				ret=(ret+dp[j][3])%mod;
				ret=(ret+dp[j][2])%mod;
			}
			dp[k][3]=(dp[k][3]+dp[j][3])%mod;
			dp[k][3]=(dp[k][3]+dp[j][2])%mod;
			dp[k][2]=(dp[k][2]+dp[j][1])%mod;
			dp[k][1]=(dp[k][1]+dp[j][0])%mod;
		}
		dp[val[i]][1]=(dp[val[i]][1]+1)%mod;
	}
	printf("%lld",ret);
	return 0;
}
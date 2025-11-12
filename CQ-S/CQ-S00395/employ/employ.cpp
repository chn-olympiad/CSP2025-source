#include<bits/stdc++.h>
using namespace std;

const int N=510,N2=18,mod=998244353;
int n,m;
char st[N];
int c[N],dp[1<<N2][N2];
int add(int x,int y){
	x+=y,x-=(x>=mod)?mod:0;
	return x;
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=18){
		int S=(1<<n)-1;
		dp[0][0]=1;
		for(int s=0;s<S;s++){
			int cnt=__builtin_popcount(s);
			for(int i=0;i<=cnt;i++){
				if(dp[s][i]==0) continue;
				for(int j=1;j<=n;j++){
					if((s>>(j-1))&1) continue;
					int fai=cnt-i,s2=s^(1<<(j-1));
					if(fai>=c[j]||st[cnt+1]=='0') dp[s2][i]=add(dp[s2][i],dp[s][i]);
					else if(st[cnt+1]=='1') dp[s2][i+1]=add(dp[s2][i+1],dp[s][i]);
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++) ans=add(ans,dp[S][i]);
		printf("%d\n",ans);
		return 0;
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			if(st[i]=='0') ans=0;
			ans=1ll*ans*i%mod;
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}

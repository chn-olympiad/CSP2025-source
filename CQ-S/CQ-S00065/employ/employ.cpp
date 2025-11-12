#include<stdio.h>
typedef long long ll;
const int N=505,M=(1<<18),Q=20,mod=998244353;
auto Mod = [](int x) -> int {return x>=mod? x-mod:x;};
int n,m,c[N],dp[M][Q];
char S[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,S);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	if(n<=18){
		dp[0][0]=1;
		for(int s=1;s<(1<<n);s++){ // state
			int now=__builtin_popcount(s); // number
			for(int i=0;i<n;i++){
				if(s>>i&1){ // the last one
					for(int j=0;j<now;j++){ // last rejected and give up
						dp[s][j+(S[now-1]=='0'||j>=c[i])]=Mod(dp[s][j+(S[now-1]=='0'||j>=c[i])]+dp[s^1<<i][j]);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++) ans=Mod(ans+dp[(1<<n)-1][i]);
		return printf("%d",ans)&0;
	}
	int f=1;
	for(int i=0;i<n;i++) if(S[i]=='0'||c[i]==0){f=0;break;}
	if(f==1){
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ll)ans*i%mod;
		printf("%d",ans);
	}
	else putchar('0');
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,Mod=998244353;
int s[N],c[N],cnt[N],pres[N],sufc[N],n,m;
int fc[N];
char in[N];
int CS[20],CSD[20],ANS;
void DFS(int x,int sum){
	if(sum==m){(ANS+=fc[n-x+1])%=Mod;return;}
	if(x==n+1)return;
	for(int i=1;i<=n;i++){
		if(CSD[i]) continue;
		CSD[i]=1;CS[x]=i;
		DFS(x+1,sum+(s[x]&&x-1-sum<c[i]));
		CSD[i]=0;CS[x]=0;
	}
}
void work1(){
	DFS(1,0);printf("%d\n",ANS);
}
void work2(){
	if(cnt[0]||pres[n]<n) printf("%d\n",0);
	else printf("%d\n",fc[n]);
}
ll dp[2][N][N];
void work3(){
	ll cs;
	dp[0][m][0]=1;
	for(int i=n;i>=1;i--){
		if(s[i]==0) continue;
		for(int d=min(i,m-1);d>=0;d--){
			for(int j=n-i;j>=0;j--){
				// dp[1][d][j]=dp[0][d][j];
				cs=sufc[i-d]-j;
				if(cs>0){
					// if(d==0&&j==2) printf("!%lld\n",cs);
					if(d<m) dp[1][d][j+1]=(dp[1][d][j+1]-1ll*cs*dp[0][d][j])%Mod;
					dp[1][d][j+1]=(dp[1][d][j+1]+1ll*cs*dp[0][d+1][j])%Mod;
				}
			}
		}
		for(int d=0;d<=m;d++){
			for(int j=0;j<=n;j++){
				(dp[0][d][j]+=dp[1][d][j])%=Mod;
				dp[1][d][j]=0;
				// printf("%lld ",dp[0][d][j]);
			}
			// printf("\n");
		}
		// printf("\n");
	}
	ll sum=0;
	for(int j=m;j<=n;j++) (sum+=dp[0][0][j]*1ll*fc[n-j])%=Mod;
	printf("%lld\n",(sum+Mod)%Mod);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%Mod;
	scanf("%s",in);
	for(int i=0;i<n;i++) s[i+1]=in[i]-'0',pres[i+1]=pres[i]+s[i+1];
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),cnt[c[i]]++;
	for(int i=n;i>=0;i--) sufc[i]=sufc[i+1]+cnt[i];
	// if(n<=10){work1();exit(0);}
	// if(m==n){work2();exit(0);}
	work3();
	return 0;
}
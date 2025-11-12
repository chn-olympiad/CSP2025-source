#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int MAXN=505,mod=998244353;
int n,m;
char s[MAXN];
int c[MAXN];
int dp[2][MAXN][MAXN][2];
void add(int &x,int y){
	x=(x+y)%mod;
}

int tot,a[MAXN];
int fac[MAXN],inv[MAXN];
int C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int A(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[n-m]%mod;
}
int cnt[MAXN<<1];
int solve(){
	for(int i=1,j=0;i<=n;i++){
		if(s[i]=='1') a[++tot]=j;
		else j++;
	}

	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=n;i++) inv[i]=inv[i-1]*inv[i]%mod;


	for(int i=1;i<=n;i++)
		for(int j=c[i];j<=n*2;j++) cnt[j]++;
	
	dp[0][0][0][0]=1;
	for(int i=1;i<=tot;i++){
		int op=i&1;
		memset(dp[op],0,sizeof(dp[op]));
		for(int j=0;j<=tot;j++){
			for(int k=0;k<=tot;k++){
				for(int o=0;o<2;o++){
					if(!dp[op^1][j][k][o]) continue;
					int pre=cnt[a[i-1]+j],now=cnt[a[i]+j+o];
					for(int l=0;l<=min(now-pre,i-1-k);l++){
						int v=A(now-pre,l)*C(i-1-k,l)%mod;
						add(dp[op][j+o][k+l][0],v*dp[op^1][j][k][o]);
						add(dp[op][j+o][k+l+1][1],v*(now-(k+l))%mod*dp[op^1][j][k][o]);
					}
				}
			}
		}
	}

	int ans=0;
	for(int j=0;j<=tot;j++){
		for(int k=0;k<=tot;k++){
			for(int o=0;o<2;o++){
				if(!dp[tot&1][j][k][o]) continue;
				if(tot-j-o<m) continue;
				add(ans,dp[tot&1][j][k][o]*A(n-cnt[a[tot]+j],tot-k));
			}	
		}
	}
	return ans*fac[n-tot]%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read();
	print(solve());
	return 0;
}
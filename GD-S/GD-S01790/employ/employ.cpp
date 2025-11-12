#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int ans;
void workA(){

	printf("%d",ans);
}
int dp[N][18];
int cnt[N],pos[N];
int p[N],pn;
int fac[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	fac[0]=fac[1]=1;
	for(int i=2;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	bool fgA=false,fgB=false;
	int cnt=0;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(m==1){
		for(int i=1;i<=n;i++) if(s[i]=='0'||c[i]==0) ans=-1;
		if(ans==-1) puts("0");
		else {
			ans=1;
			for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
			printf("%d",ans);
		} return 0;
	} else if(m==n){
		
		return 0;
	}
	for(int i=1;i<=n;i++) if(s[i]=='1') ++cnt;
	if(cnt==n) fgA=true;
	if(cnt<=18) fgB=true; 
	return 0;
} 

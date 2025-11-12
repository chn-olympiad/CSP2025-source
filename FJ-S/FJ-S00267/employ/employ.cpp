#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,mod=998244353;
int n,k;
int a[N],cnt[N],suf[N];
ll C[N][N],A[N][N],f[N][N],f1[N][N],g[N][N],ans;
char s[N]; ll P[N],FP[N];
inline void add(ll &x,ll y){x=(x+y)%mod;}
ll power(ll x,ll y){
	ll res=1ll;
	while(y){
		if(y&1ll) res=res*x%mod;
		x=x*x%mod,y>>=1ll;}
	return res;}
ll inv(ll x){return power(x,mod-2);}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
//	freopen("employ5.in","r",stdin);
//	freopen("employ5.out","w",stdout);
	
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=n;i>=0;i--) suf[i]=suf[i+1]+cnt[i];
	P[0]=1ll; for(ll i=1;i<=n;i++) P[i]=P[i-1]*i%mod;
	FP[n]=inv(P[n]); for(ll i=n;i>=1;i--) FP[i-1]=FP[i]*i%mod;
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=i;j++){
			A[i][j]=P[i]*FP[i-j]%mod;
			C[i][j]=P[i]*FP[i-j]%mod*FP[j]%mod;
		}
//	printf(":%lld\n",C[5][3]);
	
	g[0][0]=1;
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		memset(f1,0,sizeof f1);
		if(s[i]=='0'){	//	必然输 
			for(int j=0;j<=min(i,n-k);j++)
				for(int p=0;p<=i;p++){
					add(f1[j][p],g[j][p]*(n-suf[j+1]-(i-1-p)));	//	c_i <= j 中选取
					if(p+1<=suf[j+1]) add(f1[j][p+1],g[j][p]);	//	c_i >  j 中选取
				}
		}
		else{
			for(int j=0;j<=min(i,n-k);j++)
				for(int p=0;p<=i;p++){
					add(f1[j][p],g[j][p]*(n-suf[j+1]-(i-1-p)));	//	c_i <= j 中选取
					if(p+1<=suf[j+1]) add(f[j][p+1],g[j][p]);		//	c_i >  j 中选取
				}
		}
		for(int j=0;j<=i;j++)
			for(int p=0;p<=i;p++)
				if(f1[j][p])
					for(int x=max(0,p-suf[j+2]);x<=min(p,cnt[j+1]);x++)
						add(f[j+1][p-x],f1[j][p]*A[cnt[j+1]][x]%mod*C[p][x]);
		memcpy(g,f,sizeof f);
//		printf(":::%d\n",i);
//		for(int j=0;j<=n;j++){
//			for(int p=0;p<=n;p++)
//				printf("%d ",g[j][p]);
//			printf("\n");
//		}
	}
	for(ll j=0;j<=n;j++)
		for(ll p=0;p<=n;p++)
			g[j][p]=g[j][p]*P[p]%mod;
	for(ll j=0;j<=n;j++)
		if(n-j>=k)
			for(ll p=0;p<=n;p++)
				add(ans,g[j][p]);
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;}


/*

3 2
101
1 1 2



*/






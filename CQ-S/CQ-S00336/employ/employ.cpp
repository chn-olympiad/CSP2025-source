#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e6+5,base=999983,Mod=998244353;
bool SSS;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){f=(ch=='-'?-f:f);ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m;
char s[N];
int c[N];
int dp[(1<<18)][20];
bool TTT;
int vis[N];
int C[505][505];
int f[2][505][505];
int fac[N]; 
signed main(){
//	printf("%lld Mib\n",(int)(&TTT-&SSS)/1024/1024);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
C[0][0]=1;fac[0]=1;
For(i,1,N-5) fac[i]=fac[i-1]*i%Mod;
	For(i,1,500){
		C[i][0]=1;
		For(j,1,i){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	n=read(),m=read();
	scanf("%s",s+1); 
	For(i,1,n) c[i]=read();
	if(n<=18){
		dp[0][0]=1;
		For(i,0,(1<<n)-1)For(t,0,n){
			For(j,1,n){
				if(i&(1<<(j-1)))continue;
				(dp[i|(1<<(j-1))][t+(c[j]<=t||s[__builtin_popcount(i)+1]=='0')]+=dp[i][t])%=Mod;
			}
		}int ans=0;
		For(j,0,n-m){
			ans+=dp[(1<<n)-1][j];
		}ans%=Mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(m==1){
		int ans=0;
		For(i,1,n)if(s[i]=='1'){
			For(j,1,n){
				if(c[j]>=i){
					int sum=1;
					For(t,0,n+1) vis[t]=0;
					For(t,1,n)if(t!=j) vis[c[t]]++;
					For(t,1,n)vis[t]+=vis[t-1];
					int p=1;
					For(t,1,i-1){
						if(s[t]=='1'){
							sum=sum*(vis[t-1]-p+1+Mod);sum%=Mod;
							p++;
						}
					}
					For(t,1,n-p)sum=sum*t%Mod;
					ans+=sum;
					ans%=Mod;
				}
			}
		}printf("%lld\n",ans);
		return 0;
	}
	
	if(m==n){
		For(i,1,n){
			if(s[i]=='0'||c[i]==0){
				puts("0");
				return 0;
			}
		}
		int ans=1;
		For(i,1,n) ans=ans*i%Mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=500){
		int p=0;
		For(i,1,n)if(c[i]==0)p++;
		For(i,1,n) vis[c[i]]++;
		For(i,1,n+1) vis[i]+=vis[i-1]; 
		f[0][p][0]=1;
		For(i,0,n-1){
			memset(f[(i+1)&1],0,sizeof(f[(i+1)&1]));
			For(j,0,n)//可以填的0-k; 
			For(k,0,n)if(f[i&1][j][k]){
				int t=vis[k]-j;//前i个填了多少个0-k的。
				if(s[i+1]=='1'&&i-t+1<=n-vis[k])(f[(i+1)&1][j][k]+=f[i&1][j][k])%=Mod;
				if(j)For(s,0,vis[k+1]-vis[k]){
					if(i<t+s)continue;
					(f[(i+1)&1][j-1+vis[k+1]-vis[k]-s][k+1]+=f[i&1][j][k]*C[i-t][s]%Mod*fac[s]%Mod*C[vis[k+1]-vis[k]][s]%Mod*j)%=Mod;
				}
				if(s[i+1]=='0'){
					For(s,0,vis[k+1]-vis[k]){
						if(i<t+s)continue;
						(f[(i+1)&1][j+vis[k+1]-vis[k]-s][k+1]+=f[i&1][j][k]*C[i-t][s]%Mod*fac[s]%Mod*C[vis[k+1]-vis[k]][s]%Mod)%=Mod;
					}
					For(s,0,vis[k+1]-vis[k]-1){
						if(i<t+s)continue;
						(f[(i+1)&1][j+vis[k+1]-vis[k]-s-1][k+1]+=f[i&1][j][k]*C[i-t][s]%Mod*fac[s+1]%Mod*C[vis[k+1]-vis[k]][s+1]%Mod)%=Mod;
					}
					
				}
			}
		}
		int ans=0;
		For(k,0,n-m){
			int t=n-vis[k];
			ans+=f[n&1][0][k]*fac[t];ans%=Mod;
		}printf("%lld\n",ans);
		return 0;
	}
	puts("0"); 
	return 0;
}
//似乎AK了 
//如果有人看到这句话，那我就没有AK 

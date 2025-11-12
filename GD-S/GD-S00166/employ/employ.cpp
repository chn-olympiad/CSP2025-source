#include<bits/stdc++.h>
// #define int long long
#define mod 998244353ll
#define pb push_back
using namespace std;
inline int read(){
	int x=0,fl=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
const int maxn=510;
const int inf=1e9;
bool mbe;

int n,m,a[maxn],p[maxn];
char s[maxn];
int f[2][maxn][maxn],ans;
inline void inc(int &u,int v){((u+=v)>=mod)&&(u-=mod);}
int fac[maxn],C[maxn][maxn];
void work(){
	n=read();m=n-read();scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[j]<=i)p[i]=j;
	}
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=n;i++){
		C[i][0]=1;for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	f[0][0][0]=1;
	for(int i=0,o=0;i<n;i++,o=!o){
		for(int j=0;j<=i+1;j++){
			for(int k=0;j<=i+1&&k<=n-p[j];k++)f[!o][j][k]=0;
		}
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i&&k<=n-p[j];k++)if(f[o][j][k]){
				// cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
				if(s[i+1]=='1'){
					inc(f[!o][j][k+1],f[o][j][k]);
				}
				else{
					for(int t=0;t<=p[j+1]-p[j]&&t<=k+1;t++){
						inc(f[!o][j+1][k+1-t],1ll*C[p[j+1]-p[j]][t]*C[k+1][t]%mod*fac[t]%mod*f[o][j][k]%mod);
					}
				}
				int val=1ll*f[o][j][k]*(p[j]-i+k)%mod;
				for(int t=0;t<=p[j+1]-p[j]&&t<=k;t++){
					inc(f[!o][j+1][k-t],1ll*C[p[j+1]-p[j]][t]*C[k][t]%mod*fac[t]%mod*val%mod);
				}
			}
		}
	}
	for(int i=0;i<=m;i++){
		// cout<<i<<" "<<p[i]<<" "<<f[n][i][n-p[i]]<<"\n";
		inc(ans,1ll*f[n&1][i][n-p[i]]*fac[n-p[i]]%mod);
	}
	printf("%d\n",ans);
}

bool med;
int T;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	// cerr<<(&mbe-&med)/1024.0/1024.0<<" MB\n";
	
	T=1;
	while(T--)work();
}
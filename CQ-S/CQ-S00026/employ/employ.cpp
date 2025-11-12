#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
void ad(int &x,int y){
	x+=y;
	x-=(x>=mod?mod:0);
}
int n,m,C[N][N],A[N][N];
char s[N];
int c[N],sc[N];
int f[N][N],g[N][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		c[a]++;
	}
	sc[0]=c[0];
	for(int i=1;i<=n;i++) sc[i]=sc[i-1]+c[i];
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		A[i][0]=1;
		for(int j=1;j<=i;j++)
			A[i][j]=1ll*A[i][j-1]*(i+1-j)%mod;
	}
	f[0][0]=1;
	for(int i=0;i<n;i++){
		if(s[i+1]=='0'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					if(f[j][k]==0) continue;
					int w=f[j][k];
					int l=sc[j]-i+k;
					int ct=c[j+1];
					for(int p=0;p<=ct&&p<=k;p++){
						int ww=1ll*w*A[ct][p]%mod*C[k][p]%mod;
						ad(g[j+1][k+1-p],ww);
						ad(g[j+1][k-p],1ll*ww*(l+ct-p)%mod);
					}
				}
			}
		}
		else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++){
					if(f[j][k]==0) continue;
					int w=f[j][k];
					int l=sc[j]-i+k;
					int ct=c[j+1];
					ad(g[j][k+1],w);
					for(int p=0;p<=ct&&p<=k;p++){
						int ww=1ll*w*A[ct][p]%mod*C[k][p]%mod;
						ad(g[j+1][k-p],1ll*ww*l%mod);
					}
				}
			}
		}
		for(int j=0;j<=i+1;j++)
			for(int k=0;k<=i+1;k++)
				f[j][k]=g[j][k],g[j][k]=0;
	}
	int ans=0;
	for(int j=0;j<=n-m;j++){
		int k=n-sc[j];
		ans=(ans+1ll*f[j][k]*A[k][k])%mod;
	}
	printf("%d",ans);
} 

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=505,mod=998244353;
inline int Mod(int x){return x>=mod?x-mod:x;}
inline int poww(int x,int y){
	int sum=1;
	while(y){
		if(y&1)sum=1ll*sum*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return sum;
}
int n,m;
int a[N],b[N],c[N],d[N];
int fac[N],C[N][N];
int f[N][N][N];
int tmp[N][N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=fac[0]=1;i<=n;i++)
		fac[i]=1ll*i*fac[i-1]%mod;
	for(int i=C[0][0]=1;i<=n;i++)
		for(int j=C[i][0]=1;j<=i;j++)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='0'&&ch!='1')
			ch=getchar();
		a[i]=('1'-ch);
	}
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	if(n-b[n]<m){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;x=read();
		c[x]++;
	}
	d[0]=c[0];
	for(int i=1;i<=n;i++)
		d[i]=Mod(d[i-1]+c[i]);
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		memset(tmp,0,sizeof tmp);
		if(a[i+1]){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++)if(f[i][j][k]){
					//c[p[i+1]]<=j
					tmp[j+1][k]=Mod(tmp[j+1][k]+1ll*(d[j]-i+k)*f[i][j][k]%mod);
					//c[p[i+1]]>j
					tmp[j+1][k+1]=Mod(tmp[j+1][k+1]+f[i][j][k]);
				}
			}
		}else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=i;k++)if(f[i][j][k]){
					//c[p[i+1]]<=j
					tmp[j+1][k]=Mod(tmp[j+1][k]+1ll*(d[j]-i+k)*f[i][j][k]%mod);
					//c[p[i+1]]>j
					f[i+1][j][k+1]=Mod(f[i+1][j][k+1]+f[i][j][k]);
				}
			}
		}
		for(int j=1;j<=i+1;j++){
			for(int k=0;k<=i+1;k++)if(tmp[j][k]){
				for(int l=0;l<=min(k,c[j]);l++){
					f[i+1][j][k-l]=Mod(f[i+1][j][k-l]+1ll*C[c[j]][l]*C[k][l]%mod*fac[l]%mod*tmp[j][k]%mod);
				}
			}
		}
	}
	for(int j=0;j<=n;j++){
		int k=n-d[j];
		if(k==0)continue;
		f[n][j][0]=Mod(f[n][j][0]+1ll*fac[k]*f[n][j][k]%mod);
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
		ans=Mod(ans+f[n][i][0]);
	printf("%d",ans);
	return 0;
}

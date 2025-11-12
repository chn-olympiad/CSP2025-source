#include <bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m;
int p[N],C[N][N],A[N][N];
char o[N];
int a[N],s[N];
void init(){
	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=1ll*p[i-1]*i%mod;
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			A[i][j]=1ll*C[i][j]*p[j]%mod;
}
int f[2][N][N];
inline void add(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	scanf("%s",o+1);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=0;i<=n;i++)
		s[i]=a[i];
	for(int i=1;i<=n;i++)
		s[i]+=s[i-1];
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int x=0;x<=i;x++)
			for(int y=0;y<=n;y++)
				f[1][x][y]=0;
		if(o[i+1]=='0'){
			for(int x=0;x<=i;x++){
				for(int y=0;y<=n;y++){
					if(f[0][x][y]==0)
						continue;
					for(int k=0;y+k<=i&&k<=a[x+1];k++)
						add(f[1][x+1][y+k],1ll*C[i-y][k]*A[a[x+1]][k]%mod*f[0][x][y]%mod);
					for(int k=0;y+k<=i&&k<=a[x+1];k++)
						add(f[1][x+1][y+k+1],1ll*(s[x+1]-y-k)*C[i-y][k]%mod*A[a[x+1]][k]%mod*f[0][x][y]%mod);
				}
			}
		}
		else{
			for(int x=0;x<=i;x++){
				for(int y=0;y<=n;y++){
					if(f[0][x][y]==0)
						continue;
					add(f[1][x][y],f[0][x][y]);
					for(int k=0;k<=i&&k<=a[x+1];k++)
						add(f[1][x+1][y+k+1],1ll*(s[x]-y)*C[i-y][k]%mod*A[a[x+1]][k]%mod*f[0][x][y]%mod);
				}
			}
		}
		for(int x=0;x<=i+1;x++)
			for(int y=0;y<=n;y++)
				f[0][x][y]=f[1][x][y];
	}
	int ans=0;
	for(int x=0;x+m<=n;x++){
		for(int y=0;y<=n;y++){
			if(f[0][x][y]==0)
				continue;
			if(n-s[x]>=n-y)
				add(ans,1ll*C[n-y][n-y]*A[n-s[x]][n-y]%mod*f[0][x][y]%mod);
		}
	}
	printf("%d",ans);
	return 0;
}

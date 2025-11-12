#include<bits/stdc++.h> 
using namespace std;
namespace MYQ{
	int n,m,f[2][511][511],ct[511],sc[511],p[511],A[511][511],ans,C[511][511];
	char s[511];
	const int mo=998244353;
	int main(){
		scanf("%d%d%s",&n,&m,&s[1]);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			ct[x]++;
		}
		sc[0]=ct[0];
		for(int i=1;i<=n;i++)
			sc[i]=sc[i-1]+ct[i];
		n+=5;
		f[0][0][0]=1;
		p[0]=1;
		for(int i=1;i<=n;i++)
			p[i]=1ll*p[i-1]*i%mo;
		for(int i=0;i<=n;i++){
			C[i][0]=1;
			for(int j=1;j<=i;j++){
				C[i][j]=C[i-1][j-1]+C[i-1][j];
				C[i][j]>=mo?C[i][j]-=mo:0;
			}
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=i;j++)
				A[i][j]=1ll*C[i][j]*p[j]%mo;
		n-=5;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=sc[n]-sc[j];k++){
					if(f[i&1][j][k]==0)
						continue;
					if(s[i+1]=='1'){
						f[i+1&1][j][k+1]+=f[i&1][j][k];
						f[i+1&1][j][k+1]>=mo?f[i+1&1][j][k+1]-=mo:0;
					}
					int ff=1ll*f[i&1][j][k]*(sc[j]-(i-k))%mo;
					for(int w=0;w<=ct[j+1]&&w<=k;w++)
						f[i+1&1][j+1][k-w]=(f[i+1&1][j+1][k-w]+1ll*ff*A[k][w]%mo*C[ct[j+1]][w])%mo;
					if(s[i+1]=='0'){
						for(int w=0;w<=ct[j+1]&&w<=k+1;w++){
							f[i+1&1][j+1][k-w+1]=(f[i+1&1][j+1][k-w+1]+1ll*f[i&1][j][k]*A[k+1][w]%mo*C[ct[j+1]][w])%mo;
//							printf("%d %d %d    %d\n",i+1,j+1,k-w+1,f[i+1&1][j+1][k-w+1]);
						}
					}
//					printf("%d %d %d  %d\n",i,j,k,f[i&1][j][k]);
					f[i&1][j][k]=0;
				}
			}
		}
		for(int i=m;i<=n;i++){
//			printf("%d %d\n",i,1ll*f[n&1][n-i][sc[n]-sc[n-i]]*p[sc[n]-sc[n-i]]%mo);
			ans=(ans+1ll*f[n&1][n-i][sc[n]-sc[n-i]]*p[sc[n]-sc[n-i]])%mo;
		}
		printf("%d",ans);
		return 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	MYQ::main();
	return 0;
}

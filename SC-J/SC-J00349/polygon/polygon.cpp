#include<bits/stdc++.h>
const int N=5005,mod=998244353;
int n,ans,a[N],f[3][N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<=2;k++){
				f[k][i+1][j]=(f[k][i+1][j]+f[k][i][j])%mod;
				int x=std::min(N-1,j+a[i+1]),y=std::min(2,k+1);
				f[y][i+1][x]=(f[y][i+1][x]+f[k][i][j])%mod;
//				printf("%d %d %d %d\n",i,j,k,f[k][i][j]);
			}
			if(j>a[i+1])ans=(ans+f[2][i][j])%mod;//,printf("				%d %d %d\n",i,j,f[2][i-1][j]);
		}
	}
	printf("%d",ans);
}
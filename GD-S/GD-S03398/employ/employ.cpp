#include <iostream>
#include <cstdio>
using namespace std;
const int N=101;
int dp[N][N][N];
char st[N];
int ci[N];
int n,m,ans;
int main(){
	freopen("employ.in","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&ci[i]);
//	for(int i=0;i<=n;i++)
		dp[0][0][0]=1;
	for(int i=1;i<=n;i++){//ÈË 
		for(int j=1;j<=n;j++){//Ìì 
			for(int k=0;k<=j;k++){//·ÅÆú 
				if(st[j]=='1'){
					if(k-1>=ci[i])
						dp[i][k][j]+=dp[i-1][k-1][j-1];
					else
						dp[i][k][j]=dp[i-1][k][j-1];
				}
				else
					if(k-1>=0)
						dp[i][k][j]=dp[i-1][k-1][j-1];
			}
		}
	}
	for(int i=0;i<=n-m;i++){
		ans+=dp[n][i][n];
	}
	printf("%d",ans);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const int MAXN=19,S=(1<<18);
const int mod=998244353;
ll dp[2][MAXN][S];
int n,m;
int a[MAXN];
int c[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int j=0;j<i;j++){
			for(int k=0;k<(1<<n);k++){
				if(!dp[(i-1)&1][j][k])continue;
				int t=dp[(i-1)&1][j][k];
				for(int l=0;l<n;l++){
					if(k>>l&1)continue;
					if(i-1-j>=c[l+1]||!a[i]){
//						printf("%d %d %d\n",i,j,k|(1<<i));
						dp[i&1][j][k|(1<<l)]+=t;
					}else{
//						printf("%d %d %d\n",i,j+1,k|(1<<i));
						dp[i&1][j+1][k|(1<<l)]+=t;
					}
				}
			}
		}
		for(int j=0;j<=i;j++){
			for(int k=0;k<(1<<n);k++)dp[i&1][j][k]%=mod;
		}
	}
	ll ans=0;
		for(int j=m;j<=n;j++){
			for(int k=0;k<(1<<n);k++){
//				printf("%d %d %d\n",n,j,k);
				(ans+=dp[n&1][j][k])%=mod;
			}
		}
	
	printf("%lld\n",ans);
}

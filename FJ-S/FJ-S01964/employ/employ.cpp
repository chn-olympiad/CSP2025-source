#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
char s[20];
int c[20];
int f[2][20][300000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	f[0][0][0]=1;
	for(int i=0;i<=n;i++){
		memset(f[(i+1)&1],0,sizeof(f[(i+1)&1]));
		for(int j=0;j<=i;j++){
			for(int k=0;k<(1<<n);k++){
				if(__builtin_popcount(k)!=i)continue;
				for(int l=0;l<n;l++){
					if(((k>>l)&1))continue;
					if(j>=c[l] || s[i]=='0')f[(i+1)&1][j+1][k|(1<<l)]=(f[(i+1)&1][j+1][k|(1<<l)]+f[i&1][j][k])%mod;
					else f[(i+1)&1][j][k|(1<<l)]=(f[(i+1)&1][j][k|(1<<l)]+f[i&1][j][k])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)ans=(ans+f[n&1][i][(1<<n)-1])%mod;
	printf("%d",ans);
	return 0;
}
//20,16:50 

#include <bits/stdc++.h>
using namespace std;
const int N=510,M=(1<<18),mod=998244353;
int n,m,ans,a[N],f[M][19];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<=n;j++)
			for(int k=1;k<=n;k++){
				if((i>>(k-1)&1)==1)
					continue;
				if(j>=a[k]||s[__builtin_popcount(i)+1]=='0')
					(f[i+(1<<(k-1))][j+1]+=f[i][j])%=mod;
				else
					(f[i+(1<<(k-1))][j]+=f[i][j])%=mod;
			}
	for(int i=0;i<=n-m;i++)
		(ans+=f[(1<<n)-1][i])%=mod;
	printf("%d",ans);
}

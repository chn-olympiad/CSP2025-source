#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<numeric>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int N=500;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,m,ans=0;
char s[MAXN];
int c[MAXN],d[MAXN];
int A[MAXN][MAXN],C[MAXN][MAXN];
inline void init(){
	A[0][0]=1;
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		A[i][0]=1;
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			A[i][j]=1ll*A[i][j-1]*(i-j+1)%mod;
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			(C[i][j]>=mod)&&(C[i][j]-=mod);
		}
	}
}
int f[MAXN][MAXN],g[MAXN][MAXN];
inline void solve(){
	scanf("%d%d",&n,&m);
	init();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	d[0]=c[0];
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+c[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i&&j<=n-m;j++)
		{
			memcpy(g[j],f[j],sizeof(int)*(i+1));
			memset(f[j],0,sizeof(int)*(i+1));
		}
		s[i]-='0';
		for(int j=0;j<i&&j<=n-m;j++)
		{
			for(int k=0;k<i;k++)
			{
				if(!g[j][k]){
					continue;
				}
				if(!s[i]){
					for(int p=0;p<=k+1&&p<=c[j+1];p++)
					{
						f[j+1][k+1-p]=(f[j+1][k+1-p]+1ll*g[j][k]*C[k+1][p]%mod*A[c[j+1]][p])%mod;
					}
					for(int p=0;p<=k&&p<=c[j+1];p++)
					{
						f[j+1][k-p]=(f[j+1][k-p]+1ll*g[j][k]*C[k][p]%mod*A[c[j+1]][p]%mod*(d[j]-(i-1-k)))%mod;
					}
				}
				else{
					for(int p=0;p<=k&&p<=c[j+1];p++)
					{
						f[j+1][k-p]=(f[j+1][k-p]+1ll*g[j][k]*C[k][p]%mod*A[c[j+1]][p]%mod*(d[j]-(i-1-k)))%mod;
					}
					f[j][k+1]+=g[j][k];
					(f[j][k+1]>=mod)&&(f[j][k+1]-=mod);
				}
			}
		}
	}
	for(int j=0;j<=n-m;j++)
	{
		for(int k=0;k<=n;k++)
		{
			if(f[j][k]&&k<=n-d[j]){
				ans=(ans+1ll*f[j][k]*A[d[n]-d[j]][k])%mod;
			}
		}
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#ifdef LOCAL
	atexit([](){fprintf(stderr,"%.3lfs\n",(double)clock()/CLOCKS_PER_SEC);});
	#endif
	solve();
	return 0;
}
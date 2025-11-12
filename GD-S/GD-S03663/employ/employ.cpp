#include<bits/stdc++.h>
using namespace std;bool Mbe;
namespace MAOJUN{

typedef long long ll;
const int N=505,P=998244353;
int n,m,c[N];char s[N];
ll F[N],C[N][N];

inline void ad(int&x,ll y){x=(x+y)%P;}
int cnt[N],sum[N],f[N][N],g[N][N];
inline void main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)cnt[c[i]]++;
	for(int i=0;i<=n;i++)sum[i]=cnt[i];
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	for(int i=0;i<=n;i++)for(int j=C[i][0]=1;j<=i;j++)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	F[0]=1;for(int i=1;i<=n;i++)F[i]=F[i-1]*i%P;
	f[0][0]=1;
	for(int i=0;i<n;i++){
		memcpy(g,f,sizeof g);memset(f,0,sizeof f);
		for(int j=0;j<=i;j++)for(int k=0;k<=i&&k<=sum[j];k++)if(g[j][k]){
			if(s[i+1]&1)ad(f[j][k],g[j][k]);
			else for(int t=0;t<=cnt[j+1]&&t<=i-k+1;t++)
				ad(f[j+1][k+t],g[j][k]*C[cnt[j+1]][t]%P*C[i-k+1][t]%P*F[t]);
			for(int t=0;t<=cnt[j+1]&&t<=i-k;t++)
				ad(f[j+1][k+t+1],g[j][k]*C[cnt[j+1]][t]%P*C[i-k][t]%P*F[t]%P*(sum[j]-k));
		}
	}
	int as=0;
	for(int j=0;j<=n-m;j++)ad(as,f[j][sum[j]]*F[n-sum[j]]);
	printf("%d\n",as);
}

}bool Med;int main(){
#ifdef IO
	freopen("D/employ2.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	MAOJUN::main();
	return 0;
}
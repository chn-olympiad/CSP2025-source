#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace lch{
const int N=505;
const int mod=998244353;
inline void add(int &x,ll y){ x=(x+y)%mod; }
int n,m;
char a[N];
int cnt[N],sum[N];
int _[2][N][N]; auto f=_[0],g=_[1];
int main(){
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d",&x); cnt[x]++;
	}
	sum[0]=cnt[0];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		swap(f,g); memset(f,0,sizeof(_[0]));
		static int tmp[N][N]; // tmp is these trs which needs ext
		memset(tmp,0,sizeof(tmp));
		if(a[i]=='0'){
			for(int j=0;j<i;j++){
				for(int k=0;k<i;k++){
					add(tmp[j+1][k+1],g[j][k]);
					add(tmp[j+1][k],g[j][k]*(ll)(sum[j]-(i-1-k)));
				}
			}
		}else{
			for(int j=0;j<i;j++){
				for(int k=0;k<i;k++){
					add(f[j][k+1],g[j][k]);
					add(tmp[j+1][k],g[j][k]*(ll)(sum[j]-(i-1-k)));
				}
			}
		}
//		for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) if(tmp[j][k]) printf("tmp %d %d %d = %d\n",i,j,k,tmp[j][k]);
		for(int j=1;j<=i;j++){
			for(int _=cnt[j];_--;){
				for(int k=1;k<=i;k++){
					add(tmp[j][k-1],tmp[j][k]*(ll)k);
				}
			}
			for(int k=0;k<=i;k++) add(f[j][k],tmp[j][k]);
		}
//		for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) if(tmp[j][k]) printf("tmp2 %d %d %d = %d\n",i,j,k,tmp[j][k]);
//		for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) if(f[j][k]) printf("f %d %d %d = %d\n",i,j,k,f[j][k]);
	}
	static int fac[N];
	for(int i=fac[0]=1;i<N;i++) fac[i]=fac[i-1]*(ll)i%mod;
	int ans=0;
	for(int j=0;j<=n-m;j++){
		int c=sum[n]-sum[j];
		add(ans,f[j][c]*(ll)fac[c]);
	}
	printf("%d\n",ans);
	return 0;
}
}
int main(){
#ifndef LCH
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	return lch::main();
}


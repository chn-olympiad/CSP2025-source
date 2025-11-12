#include <iostream>
#include <cctype>
#include <algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=5010,mod=998244353;
int a[N],maxx[N][N],b[N];
int n,ans1,m;
inline int read() {
	int x=0; char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x;
}
void dfs(const int dp,const int k,const int mx,const int sum) {
	if(k>m) return ;
	if(dp>n) {
		if(k==m) {
			if(sum>(mx<<1)) {
				ans1++;
				if(ans1>=mod) ans1-=mod;
			}
		}
		return ;
	}
	if(b[n]-b[dp-1]+sum<=(mx<<1)) {
		return ;
	}
	if(k+n-dp+1<m) {
		return ;
	}
	if(k<=m) dfs(dp+1,k+1,max(mx,a[dp]),sum+a[dp]);
	dfs(dp+1,k,mx,sum);
}
bool check() {
	int mx=a[1];
	for(int i=2;i<=n;i++) {
		mx=max(mx,a[i]);
	}
	return mx<=1;
}
int C[N][N];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=b[i-1]+a[i];
	if(check()) {
		C[1][0]=C[1][1]=1;
		for(int i=2;i<=n;i++) {
			C[i][0]=1;
			for(int j=1;j<=i;j++) {
				C[i][j]=(1ll*C[i-1][j]+C[i-1][j-1])%mod;
			}
		}
		int ret=0;
		for(int i=3;i<=n;i++)
			ret=(1ll*ret+C[n][i])%mod;
		printf("%d\n",ret);
		return 0;
	}
	for(m=3;m<=n;m++) {
		dfs(1,0,0,0);
	}
	printf("%d",ans1);
	return 0;
}
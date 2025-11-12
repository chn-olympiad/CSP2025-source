#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 998244353
using namespace std;
int n,m,c[501];
char a[501];
inline void add(int &x,int y) {
	if((x+=y)>=mod) x-=mod;
}
namespace sol1 {
	int f[2][19][262144];
	void work() {
		f[0][0][0]=1;
		for(int i=0;i<n;++i) {
			int x=i&1,y=x^1;
			memset(f[y],0,sizeof(f[y]));
			for(int j=0;j<=i;++j)
				for(int s=(1<<n)-1;s>=0;--s) {
					if(!f[x][j][s]) continue;
					for(int k=1;k<=n;++k)
						if(s>>k-1&1^1) {
							if(a[i]=='0'||j>=c[k]) add(f[y][j+1][s|1<<k-1],f[x][j][s]);
							else add(f[y][j][s|1<<k-1],f[x][j][s]);
						}
				}
		}
		int ans=0;
		for(int i=0;i<=n-m;++i) add(ans,f[n&1][i][(1<<n)-1]);
		printf("%d",ans); 
	}
}
namespace sol2 {
	int f[501][501];
	void work() {
		sort(c+1,c+n+1);
		f[0][0]=1;
		for(int i=1;i<=n;++i)
			for(int j=0;j<=n;++j) {
				if(j-c[i]+1>0) add(f[i][j+1],1ll*f[i-1][j]*(j-c[i]+1)%mod);
				add(f[i][j],1ll*f[i-1][j]*min(i,i-(j-c[i]+1))%mod);
			}
		int ans=0;
		for(int i=0;i<=n-m;++i) add(ans,f[n][i]);
		printf("%d",ans);
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	if(n<=18) sol1::work();
	else sol2::work();
	return 0;
}

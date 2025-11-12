#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2e5;
int n,a[N+2][5],p[N+2],c[5],b[N+2];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1; i<=n; ++i) for(int j=1; j<=3; ++j) scanf("%d",&a[i][j]);
		memset(c,0,sizeof(c));
		int ans=0;
		for(int i=1; i<=n; ++i) {
			p[i]=max_element(a[i]+1,a[i]+4)-a[i];
			ans+=a[i][p[i]];
			++c[p[i]];
		}
		int k=max_element(c+1,c+4)-c;
		if(c[k]*2<=n) {
			printf("%d\n",ans);
			continue;
		}
		int m=0;
		for(int i=1; i<=n; ++i) {
			if(p[i]!=k) continue;
			int x=a[i][p[i]];
			a[i][p[i]]=-1;
			b[++m]=x-*max_element(a[i]+1,a[i]+4);
		}
		sort(b+1,b+m+1);
		for(int i=1; i<=c[k]-n/2; ++i) ans-=b[i];
		printf("%d\n",ans);
	}
	return 0;
}
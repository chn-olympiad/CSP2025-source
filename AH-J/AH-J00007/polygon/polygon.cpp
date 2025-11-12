#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005],cnt,i;
void dfs(int m,int s,int mx) {
	if(m>=n) {
		if(s>mx*2) ++cnt;
		return;
	}
	dfs(m+1,s+a[m],max(mx,a[m]));
	dfs(m+1,s,mx);
}
int main(void) {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d",&a[i]);
	dfs(0,0,0);
	printf("%d",cnt%998244353);
	return 0;
}

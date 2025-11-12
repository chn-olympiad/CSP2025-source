#include <bits/stdc++.h>
using namespace std;
const int maxn=100010; 
int a[maxn][4],b[maxn];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(n==2) {
			int ans=0;
		    for(int i=1;i<=n;i++) {
				for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
			}
		    for(int i=1;i<=3;i++) {
		    	for(int j=1;j<=3;j++) {
		    		if(i!=j) ans=max(a[1][i]+a[2][j],ans);
				}
			}
			printf("%d\n",ans);
		}else {
			long long ans=0;
			int m=0;
			for(int i=1;i<=3*n;i++) {
				int r;
				scanf("%d",&r);
				if(r!=0) b[++m]=-r;
			}
			sort(b+1,b+1+m);
			for(int i=1;i<=n/2;i++) ans+=(-b[i]);
			printf("%lld\n",ans);
		}
		
	}
	return 0;
} 

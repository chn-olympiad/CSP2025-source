#include<iostream>
using namespace std;
const int N=10006;
int t,n,a[N][4],c[N],cn[4],f1[N],f2[N];
long long ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ans=0;
		fill(c,c+N,0);
		fill(cn,cn+4,0);
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d ",&a[i][1],&a[i][2],&a[i][3]);
			int temp[4];
			fill(temp,temp+4,0);
			for(int k1=1; k1<=3; k1++) {
				for(int k2=k1+1; k2<=3; k2++) {
					if(a[i][k1]>=a[i][k2])temp[k1]++;
					else temp[k2]++;
				}
			}
			for(int k=1; k<=3; k++) {
				if(temp[k]==2) f1[i]=k;
				else if(temp[k]==1) f2[i]=k;
			}
		}
		for(int i=1; i<=n; i++) {
			int c1=f1[i],c2=f2[i];
			if(cn[c1]+1<=n/2) {
				cn[c1]++;
				c[i]=c1;
				ans+=a[i][c1];
			} else {
				int fj=0,aj=0,amax=0;
				for(int j=1; j<i; j++) {
					if(c[j]==c1) {
						aj=a[i][c1]+a[j][f2[j]];
						if(aj>a[i][c2]+a[j][c1]&&aj>amax) {
							fj=j;
							amax=aj;
						}
					}
				}
				if(fj) {
					c[fj]=f2[fj];
					c[i]=c1;
					cn[f2[fj]]++;
					ans+=amax-a[fj][c1];
				} else {
					cn[c2]++;
					c[i]=c2;
					ans+=a[i][c2];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[100005][5],b[100005],sz,mx,x,y,z,s,i;
int main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=x=y=z=s=0;i<n;++i) {
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) ++x,s+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) ++y,s+=a[i][1];
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]) ++z,s+=a[i][2];
		}
		if(x>n/2) mx=x,x=0,y=1,z=2;
		else if(y>n/2) mx=y,x=1,y=0,z=2;
		else if(z>n/2) mx=z,x=2,y=0,z=1;
		else {
			printf("%d\n",s);
			continue;
		}
		for(i=sz=0;i<n;++i) {
			if(a[i][x]>=a[i][y]&&a[i][x]>=a[i][z]) {
				if(a[i][y]>a[i][z]) b[sz++]=a[i][x]-a[i][y];
				else b[sz++]=a[i][x]-a[i][z];
			}
		}
		sort(b,b+sz);
		for(i=0,sz=mx-n/2;i<sz;++i) s-=b[i];
		printf("%d\n",s);
	}
	return 0;
}

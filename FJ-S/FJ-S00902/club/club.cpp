#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans,p[4];
struct node {
	int h[4]= {0,0,0,0},c1=0,c2=0,pos=0,lose=0;
} a[100010],b[100010],xxx;
inline bool cmp(node &x,node &y) {
	return x.lose<y.lose;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(; t--;) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].h[1],&a[i].h[2],&a[i].h[3]);
			if(a[i].h[1]>a[i].h[2]) {
				if(a[i].h[1]>a[i].h[3]){
					a[i].c1=1;
					if(a[i].h[2]>a[i].h[3]) a[i].c2=2;
					else a[i].c2=3;
				}
				else
					a[i].c1=3,a[i].c2=1;
			} 
			else {
				if(a[i].h[2]>a[i].h[3]){
					a[i].c1=2;
					if(a[i].h[1]>a[i].h[3])a[i].c2=1;
					else a[i].c2=3;
				}
				else 
					a[i].c1=3,a[i].c2=2;
			}
			p[a[i].c1]++;
			a[i].pos=i;
			a[i].lose=a[i].h[a[i].c1]-a[i].h[a[i].c2];
		}
		int zu=1;
		for(; zu<=3; zu++)
			if(p[zu]>n/2)
				break;
		int l=0;
		for(int i=1; i<=n; i++)
			if(a[i].c1==zu)
				b[++l]=a[i];
		sort(b+1,b+l+1,cmp);
		for(int i=1; i<=p[zu]-n/2; i++)
			a[b[i].pos].c1=a[b[i].pos].c2;
		for(int i=1; i<=n; i++) 
			ans+=a[i].h[a[i].c1];
		printf("%d\n",ans);
		ans=0;
		for(int i=1; i<=n; i++)a[i]=b[i]=xxx;
		p[0]=p[1]=p[2]=p[3]=0;
	}
	return 0;
}

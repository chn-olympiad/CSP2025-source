#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a[100001][3],b[100001];
void cho(int *p,int &mx,int &id) {
	mx=max(p[0],max(p[1],p[2]));
	if(mx==p[0]) id=0;
	else if(mx==p[1]) id=1;
	else id=2;
}
void work() {
	scanf("%d",&n);
	int c[3]={0,0,0},ans=0;
	for(int i=1;i<=n;++i) {
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		int mx,id;
		cho(a[i],mx,id);
		ans+=mx;
		++c[id];
	}
	int mx2,id2;
	cho(c,mx2,id2);
	int cnt=0;
	for(int i=1;i<=n;++i) {
		int mx,id;
		cho(a[i],mx,id);
		if(id==id2) {
			b[++cnt]=0;
			for(int j=0;j<3;++j)
				if(j!=id) b[cnt]=max(b[cnt],a[i][j]);
			b[cnt]-=mx;
		}
	}
	sort(b+1,b+cnt+1);
	for(int i=cnt-mx2+(n>>1)+1;i<=cnt;++i) ans+=b[i];
	printf("%d\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) work();
	return 0;
}

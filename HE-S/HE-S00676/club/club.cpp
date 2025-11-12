#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct club {
	int a,b,c;
	int num;
	bool used;
} a[N];
long long ans;
int t,n,cnt;
void dfs(int time,int ax,int bx,int cx,long long sum) {
	if(time==n) {
		ans=max(sum,ans);
		return ;
	}
//	printf("%d ",time);
	for(int i=1; i<=n; i++) {
		if(a[i].used) continue;
		if(ax<n/2) {
			a[i].used=true;
			dfs(time+1,ax+1,bx,cx,sum+a[i].a);
			a[i].used=false;
		}
		if(bx<n/2) {
			a[i].used=true;
			dfs(time+1,ax,bx+1,cx,sum+a[i].b);
			a[i].used=false;
		}
		if(cx<n/2) {
			a[i].used=true;
			dfs(time+1,ax,bx,cx+1,sum+a[i].c);
			a[i].used=false;
		}
	}
}bool cmp(club x,club y) {
	return x.a>y.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		cnt=n;
		ans=0;
		int aa=0;
		int bb=0;
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			aa+=a[i].b;
			bb+=a[i].c;
		}
		if(aa==0&&bb==0) {
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				ans+=a[j].a;
			}
			printf("%lld",ans);
			continue;
		}
		dfs(0,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}

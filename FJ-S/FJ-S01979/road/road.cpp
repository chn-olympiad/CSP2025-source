#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e4+10;
const int M=2e6+10;
int n,m,k;
int head[N],Next[M],ver[M],tot,cnt;
ll c[20],edge[M],a[20][N],ans,sum,num;
struct rec {
	int x,y;
	ll z;
}e[M],t[M],rt[M];
struct node {
	int fa[M];
	void clr(int n) {
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x) {
		if(x==fa[x]) return x;
		return fa[x]=find(fa[x]);
	}
}BCJ;
bool cmp(rec p,rec q) {
	return p.z<q.z;
}
void add(int x,int y,ll z) {
	head[x]=++tot;
	ver[tot]=y;
	Next[tot]=head[x];
	edge[tot]=z;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z);
		add(e[i].x,e[i].y,e[i].z);
		add(e[i].y,e[i].x,e[i].z);
	}
	for(int j=1;j<=k;j++) {
		scanf("%lld",&c[j]);
		for(int i=1;i<=n;i++) scanf("%lld",&a[j][i]);
	}
	sort(e+1,e+m+1,cmp);
	BCJ.clr(n);
	for(int i=1;i<=m;i++) {
		int fx=BCJ.find(e[i].x),fy=BCJ.find(e[i].y);
		if(fx!=fy) {
			BCJ.fa[fx]=fy;
			t[++cnt]=e[i];
			ans+=e[i].z;
		}
		if(cnt==n-1) break;
	}
	for(int sta=1;sta<(1<<k);sta++) {
		sum=0,cnt=n-1,num=n;
		for(int i=1;i<=cnt;i++) rt[i]=t[i];
		for(int j=1;j<=k;j++) {
			if((sta>>(j-1))&1) {
				sum+=c[j],num++;
				for(int i=1;i<=n;i++) {
					rt[++cnt].x=n+j;
					rt[cnt].y=i;
					rt[cnt].z=a[j][i];
				}	
			}
		}
		sort(rt+1,rt+cnt+1,cmp);
		BCJ.clr(n+k);
		int s=0;
		for(int i=1;i<=cnt;i++) {
			if(sum>=ans) break;
			int fx=BCJ.find(rt[i].x),fy=BCJ.find(rt[i].y);
			if(fx!=fy) {
				BCJ.fa[fx]=fy;
				sum+=rt[i].z;
				s++;
			}
			if(s==num-1) break;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
} 

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e4+10,M=1e7+1000;
int p[N];
int find(int x) {
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
struct edge {
	int e;
	int ne;
	long long w;
	int num;
} a[M];
bool cmp(edge x,edge y) {
	return x.w<y.w;
}
long long sum;
long long s[20],ss[20][20];
bool st[N][N],stt[20];
int n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		int u,v;
		long long w;
		scanf("%d %d %lld",&u,&v,&w);
		a[i]= {u,v,w,0};
	}
	for(int i=1; i<=n; i++) {
		p[i]=i;
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",&s[i]);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&ss[i][j]);
		}
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=m; j++) {
			if(a[j].w>=s[i]+ss[i][a[j].e]+ss[i][a[j].ne]) {
				a[j].w=s[i]+ss[i][a[j].e]+ss[i][a[j].ne];
				a[j].num=i;
				st[a[j].e][a[j].ne]=st[a[j].ne][a[j].e]=true;
			}
		}
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) {
			for(int l=j+1; l<=n; l++) {
				if(!st[i][j]) {
					a[++m]= {j,l,s[i]+ss[i][j]+ss[i][l],i};
				}
			}
		}
	}
	memset(st,false ,sizeof(st));
	sort(a+1,a+m+1,cmp);
//	for(int i=1; i<=m; i++) {
//		printf("%d %d %lld\n",a[i].e,a[i].ne,a[i].w);
//	}
	for(int i=1; i<=m; i++) {
		int pa=find(a[i].e),pb=find(a[i].ne);
		if(pa!=pb) {
			p[pa]=pb;
			if(a[i].num) {
				if(!stt[a[i].num]) {
					stt[a[i].num]=true;
					for(int j=i+1; j<=m; j++) {
						if(a[j].num==a[i].num) {
							a[j].w-=s[a[i].num];
							if(a[j].e==a[i].e) a[j].w-=ss[a[i].num][a[i].e];
							if(a[j].ne==a[i].ne) a[j].w-=ss[a[i].num][a[i].ne];
						}
					}
				}
			}
			sum+=a[i].w;
		}
	}
//	for(int i=1; i<=m; i++) {
//		printf("%d %d %lld\n",a[i].e,a[i].ne,a[i].w);
//	}
//	for(int i=1; i<=k; i++) {
//		if(open[i])printf("1 ");
//		else printf("0 ");
//		for(int j=1; j<=n; j++) {
//			if(openn[i][j])printf("1 ");
//			else printf("0 ");
//		}
//		printf("\n");
//	}
	printf("%lld",sum);
	return 0;
}

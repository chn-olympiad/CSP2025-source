#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10005
#define M 1000005
int n,m,k,fx,fy,cnt,tag;
int bel[N];
ll ans;
struct Path{
	int a,b,c;
	bool operator < (const Path &C) const{
		return c<C.c;
	}
}p[2*M],used[M],use[M];
struct Build{
	int cst,st;
	int val[N];
}bld[15];
void init(){
	for(int i=1;i<=n;i++) bel[i]=i;
}
int find(int x){
	if(bel[x]!=x) return bel[x]=find(bel[x]);
	return x;
}
void dfs(int x,ll sum){
	if(x>k){
		init();
		ll Max=sum;
		int tot=0;
		for(int i=1;i<=cnt;i++) used[i]=use[i];
		sort(use+1,use+1+cnt);
		for(int i=1;i<=cnt;i++){
			fx=find(use[i].a);
			fy=find(use[i].b);
			if(fx==fy) continue;
			bel[fy]=fx;
			Max+=use[i].c;
			tot++;
			if(tot==n-1) break;
		}
		ans=min(ans,Max);
		for(int i=1;i<=cnt;i++) use[i]=used[i];
		return;
	}
	int lst=cnt;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			use[++cnt]=(Path){i,j,bld[x].val[i]+bld[x].val[j]};
		}
	}
	dfs(x+1,sum+bld[x].cst);
	cnt=lst;
	dfs(x+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++) scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
	for(int i=1;i<=k;i++){
		scanf("%d",&bld[i].cst);
		for(int j=1;j<=n;j++){
			scanf("%d",&bld[i].val[j]);
			if(!bld[i].val[j]) bld[i].st=j;
		} 
		if(bld[i].cst||!bld[i].st) tag=1;
	}
	if(!tag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j==bld[i].st) continue;
				p[++m]=(Path){bld[i].st,j,bld[i].val[j]};
			}
		}
		sort(p+1,p+1+m);
		for(int i=1;i<=m;i++){
			fx=find(p[i].a);
			fy=find(p[i].b);
			if(fx==fy) continue;
			bel[fy]=fx;
			cnt++;
			ans+=p[i].c;
			if(cnt==n-1) break;
		}
		printf("%lld",ans);
		return 0;
	}
	sort(p+1,p+1+m);
	for(int i=1;i<=m;i++){
		fx=find(p[i].a);
		fy=find(p[i].b);
		if(fx==fy) continue;
		bel[fy]=fx;
		use[++cnt]=p[i];
		ans+=p[i].c;
		if(cnt==n-1) break;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}


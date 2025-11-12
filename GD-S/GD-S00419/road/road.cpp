#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 2000005
#define N 20005
int n,m,k,f[N],top,a[N],ans;
struct EDGE{int u,v,fr;}edge[M],p[15][N];
struct VL{int pt,fr;}pp[N];
bool cmp(VL a,VL b){return a.fr<b.fr;}
bool cmpp(EDGE a,EDGE b){return a.fr<b.fr;}
int find(int w){return w==f[w]?w:f[w]=find(f[w]);}
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
signed main(){
//	freopen("road.txt","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].fr);
	sort(edge+1,edge+m+1,cmpp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(find(edge[i].u)==find(edge[i].v)) continue;
		ans+=edge[i].fr;
		p[0][++top]=edge[i];
		f[find(edge[i].u)]=find(edge[i].v),find(edge[i].u);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&pp[j].fr),pp[j].pt=j;
		sort(pp+1,pp+n+1,cmp);
		for(int j=1;j<=n;j++) p[i][j].u=i+n,p[i][j].v=pp[j].pt,p[i][j].fr=pp[j].fr;
	}
	for(int i=1;i<(1<<k);i++){
		while(!q.empty()) q.pop();
		q.push({p[0][1].fr,{0,1}});
		int anss=0,upp=n-1;
		for(int j=1;j<=k;j++) if(i&(1<<(j-1))) q.push({p[j][1].fr,{j,1}}),anss+=a[j],++upp;
		for(int i=1;i<=n+k;i++) f[i]=i;
		top=0;
		while(top!=upp){
			int x=q.top().second.first,y=q.top().second.second;
			q.pop();
			if(p[x][y+1].u!=0)q.push({p[x][y+1].fr,{x,y+1}});
			if(find(p[x][y].u)==find(p[x][y].v)) continue;
			++top;
			anss+=p[x][y].fr;
			f[find(p[x][y].u)]=find(p[x][y].v),find(p[x][y].u);
		}
		ans=min(ans,anss);
	}
	printf("%lld\n",ans);
	return 0;
}

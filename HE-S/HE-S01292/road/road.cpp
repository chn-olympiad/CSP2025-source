#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=1e6+100;
int n,m,k,c[N],a[11][N],h[11],cnt[11];
bool vis[11];
ll ans;
struct edge{
    int u,v,w,id;
	bool operator < (edge t)const{
		return w>t.w;
	}
}e[M],p[11][N];
priority_queue<edge>q;
bool cmp(edge fir,edge sec){
	return fir.w<sec.w;
}
int fa[N],siz[N];
void clear(){
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(siz[fx]<siz[fy])swap(fx,fy);
	fa[fy]=fx;
	siz[fx]+=siz[fy];
}
void init(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			p[0][++cnt[0]]=e[i];
		}
	}
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
	clear();
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		ans+=e[i].w;
    }
	init();
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			p[i][j].u=i+n;
			p[i][j].v=j;
			p[i][j].w=a[i][j];
			p[i][j].id=i;
		}
		sort(p[i]+1,p[i]+n+1,cmp);
		cnt[i]=n;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int s=0;s<(1<<k);s++){
		memset(vis,0,sizeof(vis));
		vis[0]=1;
		for(int j=1;j<=k;j++)vis[j]=((s>>(j-1))&1);
		ll res=0;
		for(int i=0;i<=k;i++){
			if(vis[i]){
				q.push(p[i][1]);
				h[i]=1;
				res+=c[i];
			}
		}
		clear();
		int num=0;
		while(!q.empty()){
			edge d=q.top();
			q.pop();
			if(find(d.u)!=find(d.v)){
				num++;
				merge(d.u,d.v);
				res+=d.w;
			}
			if(h[d.id]<cnt[d.id]){
				h[d.id]++;
				q.push(p[d.id][h[d.id]]);
			}
			if(res>ans)break;
		}
		while(!q.empty())q.pop();
		ans=min(ans,res);
	}
	cout<<ans;
}
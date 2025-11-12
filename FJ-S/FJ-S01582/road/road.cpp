#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11,M=1e5+11;
typedef pair<long long,long long> PII;
int n,m,k,cnt=1,d;
bool vis[M];
long long dis[M],ahead[11][M],vi[M];
int head[M];
long long f[M],minn=0x3f3f3f3f;
struct node{
	int v;
	long long w;
	int next;
}edge[N];
struct e{
	int u,v;
	long long w;
}ed[N];
void add(int u,int v,long long w){
	edge[cnt]={v,w,head[u]};
	head[u]=cnt++;
}
long long djs(int x){
	long long t=0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(vi,0,sizeof(vi));
	priority_queue<PII,vector<PII>,greater<PII> >q;
	dis[x]=0;
	vis[x]=true;
	q.push({0,x});
	while(!q.empty()){
		PII tmp=q.top();
		q.pop();
		long long u=tmp.second;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].v;
			long long w=edge[i].w;
			if(dis[v]>=dis[u]+w){
				t=t-edge[vi[v]].w+w;
				dis[v]=dis[u]+w;
				vi[v]=i;
				if(vis[v])continue;
				vis[v]=true;
				q.push({dis[v],v});
			}
		}		
		cout<<endl;	
	}
	return t;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d %d %d",&n,&m,&k);
	int u,v;
	long long w;
	for(int i=1;i<=m;++i){
		scanf("%d %d %lld",&u,&v,&w);
		ed[i]={u,v,w}; 
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;++i){
		scanf("%lld",&f[i]);
		for(int j=1;j<=n;++j){
			scanf("%lld",&w);
			ahead[i][j]=w;
		}
	}
	minn=min(minn,djs(1));
	long long s=0;
	for(int l=1;l<=k;++l){
		for(int i=l;i<=k;++i){
			for(int j=1;j<=n;++j){
				add(i+n,j,ahead[i][j]);
				add(j,i+n,ahead[i][j]);
			}
			s+=f[i];
			d=i-l+1;
			minn=min(minn,djs(1)+s);
		}
		d=s=0;
		cnt=1;
		memset(head,-1,sizeof(head));
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=m;++i){
			add(ed[i].u,ed[i].v,ed[i].w);
			add(ed[i].v,ed[i].u,ed[i].w);
		}
	}
	printf("%lld",minn);
	return 0;
}

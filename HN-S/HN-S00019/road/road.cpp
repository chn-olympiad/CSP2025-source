#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+25,M=2e6+5; 
int n,m,k,head[N],tot,a[N],g[15][N];
int ans=0x3f3f3f3f3f3f3f3f;
int dis[N],vis[N],fa[N],lfa[25];
struct edge{
	int to,next,w;
}e[M*2];
void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].next=head[u];
	e[tot].w=w;
	head[u]=tot;
}
struct node{
	int x,w;
	bool operator<(const node& s)const {
		return s.w<w;
	}
};
struct tr{
	int u,v,w;
}t[M],lt[N],st[N];
priority_queue<node> q;
void Prim(){
	q.push((node){1,0});
	for (int i=1;i<=n;i++)	dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	dis[1]=0;
	while(q.size()){
		int u=q.top().x;q.pop();
		if(vis[u])	continue;vis[u]=1;
		for (int i=head[u];i;i=e[i].next){
			int v=e[i].to,w=e[i].w;
			if (vis[v])	continue;
			if (dis[v]>w){
				fa[v]=u;
				dis[v]=w;
				q.push((node){v,w});
			}
		}
	}
	int res=0;
	for (int i=1;i<=n;i++){
		res+=dis[i];
	}
	ans=min(ans,res);
}

bool cmp(tr x,tr y){
	return x.w<y.w;
}
int ft[N];
int find(int x){
	if (x==ft[x])	return x;
	return ft[x]=find(ft[x]);
}
int tt=n-1,bk[N],cn=n-1;
void Kruskal(int id){
	for (int i=1;i<=tt;i++)	st[i]=t[i];
	st[0].u=tt;
	for (int i=1;i<=n;i++){
		t[tt+i].u=id+n,t[tt+i].v=i,t[tt+i].w=g[id][i];
	}tt+=n;cn++;
//cout<<tt<<endl;
//	for (int i=1;i<=tt;i++){
//		cout<<t[i].u<<' '<<t[i].v<<' '<<t[i].w<<endl;
//	}
	memset(lt,0,sizeof(lt));
	memset(lfa,0,sizeof(lfa));
	memset(bk,0,sizeof(bk));
	for (int i=0;i<=n+k+1;i++)	ft[i]=i;
	sort(t+1,t+tt+1,cmp);
	int cc=0,sum=0;
	for (int i=1;i<=tt;i++){
		if (t[i].u>t[i].v)	swap(t[i].u,t[i].v);
		int u=find(t[i].u),v=find(t[i].v),w=t[i].w;
		if (u==v)	continue;
		ft[u]=v;
		if (bk[t[i].v]==0&&t[i].v>n)	sum+=a[v-n],lfa[t[i].v-n]=w;
		bk[t[i].v]++;
		cc++;sum+=w;
//		cout<<t[i].u<<' '<<t[i].v<<' '<<w<<endl;
		lt[cc].u=t[i].u;lt[cc].v=t[i].v;lt[cc].w=w;
		
		 if (cn==cc)	break;
	}
//	cout<<sum<<endl;
	for (int i=n+1;i<=id+n;i++){
		if (bk[i]==1)	sum-=a[i-n],sum-=lfa[i-n],cn--;
	}
	if (sum>ans){
		tt-=n;cn--;bk[id+n]=1;
		for (int i=1;i<=n;i++)	t[tt+i].u=t[tt+i].v=t[tt+i].w=0;
		for (int i=1;i<=st[0].u;i++)	t[i]=st[i];
	}else{
		tt=cc;
		int j=0;
		memset(t,0,sizeof(t));
		for (int i=1;i<=tt;i++){
			if(bk[lt[i].v]==1&&lt[i].v>n) continue;
			t[++j]=lt[i];
		}
		ans=sum;tt=j;
	}
//	for (int i=1;i<=tt;i++)	cout<<t[i].u<<' '<<t[i].v<<' '<<t[i].w<<endl; 
//cout<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	cin>>n>>m>>k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for (int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		for (int j=1;j<=n;j++){
//			cin>>g[i][j];
			scanf("%lld",&g[i][j]);
		}
	}
	Prim();tt=n-1,cn=n-1;
	for (int i=2;i<=n;i++){
		t[i-1].u=i;t[i-1].v=fa[i];t[i-1].w=dis[i];
	}
	for (int i=1;i<=k;i++){
		Kruskal(i);
	}
	cout<<ans;
	return 0;
}


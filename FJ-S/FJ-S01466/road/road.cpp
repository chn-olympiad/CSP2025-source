#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=2e6+1e5+5;
struct edge{
	int to,next,from,w;
}e[M];
struct node{
	int u,dis;
	bool operator <(const node& a)const{
		return dis>a.dis;
	}
};
int n,m,k,u,v,w,c,a[N],head[N],ans,cnt,f[N],dis[N],cnt1,cnt2,h;
void add(int from,int to,int w){
	e[++cnt].to=to;
	e[cnt].next=head[from];
	e[cnt].w=w;
	e[cnt].from=from;
	head[from]=cnt;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void kruskal(){
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=cnt;i++){
		if(cnt==n-1)break;
		int x=find(e[i].from),y=find(e[i].to);
		if(x!=y){
			f[x]=y;
			ans+=e[i].w;
			cnt++;
		}
	}
}
void dij(int x){
	priority_queue<node>q;
	q.push({x,0});
	memset(dis,0x3f,sizeof dis);
	dis[x]=0;
	while(!q.empty()){
		int u=q.top().u,dist=q.top().dis;
		q.pop();
		if(dis[u]!=dist)continue;
		for(int i=head[u];i&&i<=cnt;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		dij(i);
		cnt1=0,cnt2=0;
		h=head[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			add(i,j,a[i]+a[j]);
			add(j,i,a[i]+a[j]);
		}
		for(int j=1;j<=n;j++)cnt1+=dis[j];
		dij(i);
		for(int j=1;j<=n;j++)cnt2+=dis[j];
		if(cnt1-cnt2>c){
			ans+=c;
		}else{
			cnt-=2*n;
			for(int j=1;j<=n;j++)head[j]=e[head[j]].next;
			head[i]=h;
		}
	}
	kruskal();
	cout<<ans;
	return 0;
}

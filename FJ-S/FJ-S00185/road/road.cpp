#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int M=4e6+10;
const int K=11;

int n,m,k,u,v,w,rcnt,head[N],fa[N],kr[K][N],ans,kid[K];

struct edge{
	int from;
	int to;
	int next;
	int w;
	bool used;
}r[M];

void add(int u,int v,int w){
	r[++rcnt].to=v;
	r[rcnt].from=u;
	r[rcnt].next=head[u];
	head[u]=rcnt;
	r[rcnt].w=w;
}

int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}

void kruskal(){
	int fu,fv,tcnt=0;
	for(int i=1;i<=rcnt;i++){
		u=r[i].from,v=r[i].to;
		fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fv]=fu;
		tcnt++;
		ans+=r[i].w;
		r[i].used=true;
		if(tcnt==2*(n+k)-1)break;
	}
}

bool cmp(edge e1,edge e2){
	return e1.w<e2.w;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		add(i,i+n,0);
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v+n,w);
		add(u+n,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>w;
		u=2*n+i,v=2*n+k+i;
		add(u,v,w);
		kid[i]=rcnt;
		for(int j=1;j<=n;j++){
			cin>>w;
			add(u,j,w);
			add(v,j+n,w);
		}
	}
	for(int i=1;i<=(n+k)*2;i++)fa[i]=i;
	sort(r+1,r+1+rcnt,cmp);
	kruskal();
	for(int i=1;i<=k;i++){
		if(r[kid[i]].used)continue;
		u=2*n+i,v=2*n+k+i;
		for(int j=head[u];j;j=r[j].next){
//			cout<<"(k1)"<<i<<"->"<<r[j].to;
			if(j!=kid[i] and r[j].used){
				ans-=r[j].w;
//				cout<<"[-"<<r[j].w<<']';
			}
//			cout<<' ';
		}
//		cout<<'\n';
		for(int j=head[v];j;j=r[j].next){
//			cout<<"(k2)"<<i<<"->"<<r[j].to;
			if(j!=kid[i] and r[j].used){
				ans-=r[j].w;
//				cout<<"[-"<<r[j].w<<']';
			}
//			cout<<' ';
		}
//		cout<<'\n';
	}
	cout<<ans;
	return 0;
}

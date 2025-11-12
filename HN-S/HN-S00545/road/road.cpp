#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+7,M=1e4+37;
struct edge{
	int to,ne,len;
}e[N];
struct node{
	ll val,id;
	bool operator <(const node &oth)const{
		return val==oth.val?id>oth.id:val>oth.val;
	}
};
int n,m,k,tot,pre[N];
void add(int u,int v,int w){
	e[++tot]={v,pre[u],w};
	pre[u]=tot;
}
int c[M],a[17][M];
priority_queue<node>pq;
ll wi[N];
bool vis[N],flag[37];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	} 
	ll A=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		A+=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			A+=a[i][j];
			add(n+i,j,a[i][j]);
			add(j,n+i,a[i][j]);
		}
	}
	if(A==0){
		cout<<0;
		return 0; 
	} 
	for(int i=1;i<=n+k+10;i++){
		wi[i]=LONG_LONG_MAX;
	}
	wi[1]=0;
	pq.push({0,1});
	while(!pq.empty()){
		int id=pq.top().id;
		ll vi=pq.top().val;
		pq.pop();
		if(vis[id])continue;
		vis[id]=1;
		for(int i=pre[id];i;i=e[i].ne){
			int to=e[i].to;
			if(vis[to])continue;
			if(to>n){
				if(wi[to]>vi+e[i].len+c[to-n]&&!flag[to-n]){
					wi[to]=vi+e[i].len+c[to-n];
					
					pq.push({wi[to],to});
				}else if(wi[to]>vi+e[i].len){
					wi[to]>vi+e[i].len;
					pq.push({wi[to],to});
				}
			}else{
				if(wi[to]>vi+e[i].len){
					wi[to]=vi+e[i].len;
					pq.push({wi[to],to});
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,wi[i]);
	}cout<<ans;
	return 0;
}

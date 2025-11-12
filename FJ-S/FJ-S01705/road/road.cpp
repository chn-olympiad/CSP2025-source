#include <bits/stdc++.h>
using namespace std;
const int N=1e4+30;
const int M=2e6+5;
int n,m,k,a[N],dis[N];
bool vis[N],cnt[M];
long long ans;
struct Edge{
	int to,w;
	int id;
	bool operator > (const Edge b)const{
		return w>b.w;
	}
};
priority_queue <Edge,vector<Edge>,greater<Edge>> q;
vector <Edge> e[N];
void dij(int st){
	memset(dis,0x7f,sizeof(dis));
	vis[st]=1;
	Edge now;
	now.to=st,now.w=0,now.id=0;
	q.push(now);
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().to,ww=q.top().w;
		q.pop();
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].to,len=e[u][i].w;
			if(dis[v]>ww+len){
				dis[v]=ww+len;
				cnt[e[u][i].id]=1;
				Edge noww;
				noww.to=v,noww.w=dis[v],noww.id=e[u][i].id;
				q.push(noww);
			}
		} 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Edge now;
		now.to=v,now.w=w,now.id=i;
		e[u].push_back(now);
		now.to=u;
		e[v].push_back(now);
	}
	for(int i=1;i<=k;i++){
		int c,x;
		cin>>c;
		Edge now;
		for(int j=1;j<=n;j++){
			cin>>x;
			now.to=j,now.w=c+x,now.id=m+(i-1)*n+j;
			e[n+i].push_back(now);
			now.to=n+i;
			e[j].push_back(now);
			if(c+x==0) a[j]=1;
		}
	}
	bool op=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			op=1;
			break;
		}
	}
	if(!op){
		cout<<'0';
		return 0;
	}
	dij(1);
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<e[i].size();j++){
			if(cnt[e[i][j].id]){
				ans+=e[i][j].w;
				cnt[e[i][j].id]=0;
			}
		}	
	}
	cout<<ans;
	return 0;
}


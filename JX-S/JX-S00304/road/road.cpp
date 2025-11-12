#include<bits/stdc++.h>
using namespace std;
struct side{
	int node,val; 
};
int n,m,k,u,v,w;
long long c[15],ans=100861145141919810,tot,sum,s,len,a,b,d,g;
bool vis[15],z,con[1015],viss[15];
vector<side>e[1015];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>qq;
void rp(int sum){
	s=1;
	for(int i=2;i<=n+k;i++){
		con[i]=0;
	}
	con[1]=1;
	for(int i=1;i<sum;i++){
		len=e[s].size();
		for(int j=0;j<len;j++){
			if(con[e[s][j].node]==0)qq.push({e[s][j].val,{e[s][j].node,s}});
		}
		while(!qq.empty()){
			a=qq.top().first;
			b=qq.top().second.first;
			d=qq.top().second.second;
			qq.pop();
			if(con[b])continue;
			con[b]=1;
			s=b;
			if(d>n)viss[d-n]=1;
			break;
		}
	}
}
int p(int sum){
	s=1;
	g=0;
	for(int i=2;i<=n+k;i++){
		con[i]=0;
	}
	con[1]=1;
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<sum;i++){
		len=e[s].size();
		for(int j=0;j<len;j++){
			if(e[s][j].node<=n&&con[e[s][j].node]==0)q.push({e[s][j].val,e[s][j].node});
			else if(vis[e[s][j].node-n]&&con[e[s][j].node]==0)q.push({e[s][j].val,e[s][j].node});
		}
		z=0;
		while(!q.empty()){
			a=q.top().first;
			b=q.top().second;
			q.pop();
			if(con[b])continue;
			g+=a;
			con[b]=1;
			s=b;
			z=1;
			break;
		}
	}
	return g;
}
void dfs(int x){
	if(x==k+1){
		sum=n;
		for(int i=1;i<=k;i++){
			if(vis[i])sum++;
		}
		tot=p(sum);
		for(int i=1;i<=k;i++){
			if(vis[i])tot+=c[i];
		}
		ans=min(ans,tot);
		return;
	}
	if(viss[x]){
		vis[x]=1;
		dfs(x+1);
	}
	vis[x]=0;
	dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		u=n+i;
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			v=j;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	rp(n+k);
	dfs(1);
	printf("%lld\n",ans);
    return 0;
}

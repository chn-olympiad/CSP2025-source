#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=2e4+10,M=1e6+10;
ll n,m,k,p,x,y,w,res,cnt,kc,ans=0x3f3f3f3f,dist[N],c[N];
bool use[N],vis[N];
struct node{
	ll p,w;
	bool operator <(const node &a)const{
		return w>a.w;
	}
};
vector<node>P[N];
void Prim(){
	priority_queue<node>q;
	memset(dist,0x3f,sizeof dist);
	memset(vis,false,sizeof vis);
	dist[1]=0,cnt=0;
	q.push({1,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int u=t.p;
		if(cnt==p+kc)break;
		if(vis[u]||!use[u])continue;
		vis[u]=true,cnt++;
		if(cnt==p+kc)break;
		for(node i:P[u]){
			int v=i.p,w=i.w;
			if(cnt==p+kc)break;
			if(dist[v]>w&&!vis[v]){
				dist[v]=w;
				q.push({v,w});
			}
		}
		if(cnt==p+kc)break;
	}
	for(int i=1;i<=n;i++)
	res+=(use[i]? dist[i]:0);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>x>>y>>w,
    P[x].push_back({y,w}),P[y].push_back({x,w}),use[x]=use[y]=true;
    p=n;
    for(int i=1;i<=k;i++){
    	cin>>c[i],n++;
    	for(int j=1;j<=p;j++)cin>>w,
    	P[n].push_back({j,w}),P[j].push_back({n,w});
	}
	for(int i=0;i<(1<<k);i++){
		res=0,kc=0;
		for(int j=0;j<k;j++){
			use[j+p+1]=false;
			if(i&(1<<j))use[j+p+1]=true,kc++,res+=c[j+1];
		}
		Prim();
		ans=min(ans,res);
	}
	cout<<ans;
    return 0;
}
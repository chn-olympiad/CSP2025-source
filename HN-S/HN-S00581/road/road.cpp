#include<bits/stdc++.h>
using namespace std;
const int N=1e7+15;
typedef long long ll;
struct edge{
	ll to,next;
	ll w;
}e[N];
ll n,m,k,vis[N],head[N];
ll p[N];
void add(ll u,ll v,ll w){
	static ll cnt=1;
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt++;
}
struct node{
	ll p;
	ll dis;
	bool operator<(node other)const{return dis<other.dis;}
	bool operator>(node other)const{return dis>other.dis;}
};
ll prim(){
	priority_queue<node,vector<node>,greater<node> >q;
	q.push((node){1,0});
	ll cnt=0,ans=0;
	while(!q.empty()){
		node cur=q.top();
		q.pop();
		ll u=cur.p;
		if(vis[u])continue;
		vis[u]=1;
		ans+=cur.dis;
//		cout<<cur.p<<"dis="<<cur.dis<<endl;
		if(cur.p<=n)cnt++;
		if(cnt==n)return ans;
		for(ll i=head[u];i;i=e[i].next){
			ll v=e[i].to;
			if(vis[v])continue;
			ll w=e[i].w;
			if(v>n)w+=p[v];
//			cerr<<"ADD"<<u<<"->"<<v<<" w="<<w<<endl;
			q.push((node){v,w});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v;
		ll w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(ll i=m+1;i<=m+k;i++){
		cin>>p[i];
		for(ll j=1;j<=n;j++){
			ll w;
			cin>>w;
			add(i,j,w);
			add(j,i,w);
		}
	}
	ll ans=prim();
	cout<<ans<<endl;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

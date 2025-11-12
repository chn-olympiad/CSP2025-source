#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;
typedef long long ll;
ll town[15][N];
ll n,m,k;
bool b[N];
ll ans=0;
ll cnt=0;
struct node{
	ll id,w;
};

struct qu{
	ll now,dis,tp;
};

bool operator<(qu x,qu y){
	return x.dis > y.dis;
}

vector<node> g[N];
priority_queue<qu> q;


void bfs(){
	q.push({1,0,0});
	while(!q.empty()){
		
		qu x=q.top();
		ll now=x.now,dis=x.dis,tp=x.tp;
		q.pop();
		
		if(b[now]) continue;
		b[now]=1;
	//	cout<<"now:"<<now<<"; dis:"<<dis<<"; tp:"<<tp<<" *"<<endl;
		ans+=dis;
		if(now<=n) cnt++;
		if(cnt==n){
			cout<<ans<<endl;
			return ;
		}
		
		if(now>n){
			for(int i=1;i<=n;i++){
				if(b[i]) continue;
				q.push({i,town[now-n][i],tp});
			}
			continue;
		}
		
		for(int j=0;j<g[now].size();j++){
			node t=g[now][j];
			if(b[t.id]) continue;
			q.push({t.id,t.w,tp});
		}
		
		for(int i=1;i<=k;i++){
			if((tp&(1<<i))){
				q.push({i+n,town[i][now],tp});
			}else{
				q.push({i+n,town[i][now]+town[i][0],tp|(1<<i)});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w}); 
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>town[i][0];
		for(int j=1;j<=n;j++) cin>>town[i][j];
	}
	ans=0,cnt=0;
	//cout<<"n="<<n<<endl;
	bfs();
	return 0;
}

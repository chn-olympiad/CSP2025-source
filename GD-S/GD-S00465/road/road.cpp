#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
using ll=long long;
ll c[13];
using tp=tuple<ll,int>;
bool operator<(tp&a,tp&b){
	return get<0>(a)>get<0>(b);
}
priority_queue<tp>q;
bool vis[N];
ll mp[N][N],dis[N];
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(mp,0x3f,sizeof(mp));
	memset(dis,0x3f,sizeof(dis));
	const int INF=mp[0][0];
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u=0,v=0,w=0;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i]; 
		for(int j=1;j<=n;++j){
			int a;
			cin>>a;
			mp[i][j]=mp[j][i]=a;
		}
	}
	q.push(make_tuple(0,1));
	ll ans=0;int cnt=0;
	while(!q.empty()&&cnt<n){
		ll le;int h;
		++cnt;
		tie(le,h)=q.top();
		q.pop();
		if(vis[h])continue;
		vis[h]=1;
		ans=max(ans,le);
		for(int i=1;i<=n;++i){
			if(!vis[i]&&dis[i]>mp[h][i]+le){
				dis[i]=le+mp[h][i];
				q.push(make_tuple(dis[i],i));
//				cerr<<'&'<<'\n';
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int M=1e4+5;
typedef pair<ll,ll> PII;
const ll INF=1e10+5;
ll n,m,k,u,v,w,val,ans=0,c[N],mp[M][M],va[M][M];
vector<PII> G[N];
vector<int> pos;
bool vis[N],flag1=0;
inline void bfs(){
	pos.push_back(1);
	vis[1]=1;
	bool flag=0;
	while(!flag){
		ll mn=INF;
		int nxt;
		for(int i=0;i<(int)pos.size();i++){
			int now=pos[i];
			for(int j=0;j<(int)G[now].size();j++){
				if(mn>G[now][j].second&&!vis[G[now][j].first]){
					mn=G[now][j].second;
					nxt=G[now][j].first;
				}
			}
		}
		ans+=mn;
		pos.push_back(nxt);
		vis[nxt]=1;
		int tmp=0;
		for(int i=1;i<=n;i++) if(vis[i]==1) tmp++;
		if(tmp==n) flag=1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(mp,0x3f3f3f3f,sizeof(mp));
	cout<<mp[1][1];
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
		G[u].push_back({v,mp[u][v]});
		G[v].push_back({u,mp[u][v]});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>val;
			va[i][j]=val;
			if(val!=0){
				flag1=1;
			}
		}
	}
	if(k==0){
		bfs();
		cout<<ans;
	}
	else{
		if(flag1){
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(j==1){
						G[i+n].push_back({j,va[i][j]+c[i]});
						G[j].push_back({n+i,va[i][j]+c[i]});
					}
					else{
						G[i+n].push_back({j,va[i][j]});
						G[j].push_back({i+n,va[i][j]});
					}
				}
			}
			bfs();
			cout<<ans;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}

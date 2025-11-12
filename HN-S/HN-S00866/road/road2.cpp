#include <bits/stdc++.h>

#define fst first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using p_q = priority_queue<pair<pair<ll,int>,pair<int,int> > >;

const int N = 1e4+50,M=2e6+50;

//pair<ll,pair<int,int> > ed[M],ed1[M];
ll ct[15][N];
int fa[N];
int isbx[15];
int mnid[15];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("sol.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	p_q q;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		q.push(mp(mp(-w,0),mp(u,v)));
	}
	for(int i=1;i<=k;i++){
		cin>>ct[i][0];ll mn=1e18; 
		for(int j=1;j<=n;j++){
			cin>>ct[i][j];
			if(mn>ct[i][j]){
				mn=ct[i][j],mnid[i]=j;
			}
		}
		if(mn+ct[i][0]<=0){
			isbx[i]=1;
		}
		for(int j=1;j<=n;j++){
			q.push(mp(mp(-ct[i][0]-mn-ct[i][j],i),mp(mnid[i],j)));
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	ll ans=0;
	while(q.size()){
		ll w=-q.top().fst.fst;
		int id=q.top().fst.sec,u=q.top().sec.sec,v=q.top().sec.fst;
		q.pop();
		int X=find(u),Y=find(v);
		if(X==Y) continue;
		fa[X]=Y,n--,ans+=w;
		if(id){
			for(int j=1;j<=n;j++){
				q.push(mp(mp(-ct[id][j],0),mp(mnid[id],j)));
			}
		} 
		if(n==1) break;
	}
	
	cout<<ans<<endl;

	return 0;
}


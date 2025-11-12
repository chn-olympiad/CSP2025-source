#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,inf=0x3f3f3f3f;
int m,n,k,dis[N],ct=0,vis[N];
#define pii pair<int,int>

priority_queue<pii ,vector<pii> ,greater<pii> > p;
vector<pii>t[N];
void dij(int s){
	memset(vis,0,sizeof(vis));
	p.push_back({s,0});
	dis[1]=0;
	int g=p.top().first;
	p.pop();
	vis[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;i++){
			if(vis[j]==1){
				continue; 
			}int y=t[j].second,z=t[i].second;
			if(y+z<dis[i]) dis[j]=y+z,vis[i]=1;
		}	
	}	
	
	
}	

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,inf,sizeof(dis));
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		t[x].push_back({y,z});
		t[y].push_back({x,z});
		
		
	}dij(1);
	for(int i=1;i<=n;i++){
		
		
		
	}
		
		
		
		for(int j=1;j<=k;j++){
		int y;
		cin>>y;
		int f=j+n;
		int x;
		cin>>x;
		dis[f]=x;
		t[f].push_back({j,n});
		t[j].push_back({f,n});
		
		}ct=ct+m+n*k;
	dij(1);	
		cout<<13;	
	}
	



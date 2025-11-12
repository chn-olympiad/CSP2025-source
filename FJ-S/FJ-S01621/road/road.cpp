#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+105;
const int inf=1e9+5;

int n,m,k;
vector<pair<int,int>>adj[N];
ll a[N],ans,vis[N],c[15],t[15];

void dfs(int id){
	queue<int>q;
	q.push(id);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=0;i<adj[p].size();i++){
			pair<int,int>t;
			t=adj[p][i];
			if(a[t.first]+c[vis[t.first]]>a[p]+t.second+c[vis[p]]){
				if(vis[t.first]==vis[p]){
					q.push(t.first);
					a[t.first]=a[p]+t.second;
				}
				else{
					q.push(t.first);
					a[t.first]=a[p]+t.second;
					if(t.first<=n)vis[t.first]=vis[p];
					else {
						a[t.first]+=c[vis[p]];
					}
				}
			}
		}
		
	}
	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,inf,sizeof(a));
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++){
			cin>>w;
			adj[n+i].push_back(make_pair(j,w));
			adj[j].push_back(make_pair(n+i,w));
			vis[n+i]=i+n;
		}
	}
	a[1]=0;
	dfs(1);
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(!t[vis[i]]){
			ans+=c[vis[i]];
			t[vis[i]]=1;
		}
	}
		
	cout<<ans;
	return 0;
}


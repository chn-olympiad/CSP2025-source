#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=15;
bool fa;
int fc;
priority_queue<array<long long,3> >q;
int now,n,m,k,u,v,w,c[M],a[M][N],cost;
long long ans,res;
bool vis[N];
vector<array<long long,2> >e[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)fa=1;
		fc=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0&&fc==0){
				fc=j;
			}
		}
		for(int k=1;k<=n;k++){
			if(k!=fc)e[fc].push_back({k,a[i][k]});
		}
	}
	if(!fa){
		q.push({-0,1,0});
		for(int i=1;i<=n;i++){
			while(!q.empty()){
				now=q.top()[1];
				res=-q.top()[0];
				cost=q.top()[2];
				q.pop();
				while(vis[now]&&!q.empty()){
					now=q.top()[1];
					res=-q.top()[0];
					cost=q.top()[2];
					q.pop();
				}
				if(vis[now])break;
				vis[now]=1;
				ans+=1ll*cost;
				for(int i=0;i<e[now].size();i++){
					if(!vis[e[now][i][0]])q.push({-res-1ll*e[now][i][1],e[now][i][0],e[now][i][1]});
				}
			}
		}	
	}
	cout<<ans;
	return 0;
} 

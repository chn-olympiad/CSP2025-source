#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > >f(1010);
int p[1010];
bool p1[1010];
const int INF=1e9;
int c[1001000];
int solve(int ans,int now,int st){
	queue<int> q;
	q.push(now);
	while(!q.empty()){
		int e=q.front();
		for(int i=0;i<f[e].size();i++){
			if(p1[f[e][i].first])
				continue;
			q.push(f[e][i].second);
			if(p[f[e][i].first]){
				p[f[e][i].first]=min(p[f[e][i].first],f[e][i].second);
			}else{
				p[f[e][i].first]=f[e][i].second;
			}
		}
		q.pop(); 
		p1[e]=1;
	} 
	return 0;
}
int main(){
	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u].push_back(make_pair(v,w));
		f[v].push_back(make_pair(u,w));
	}

	for(int j=1;j<=k;j++){
		int q;
		cin>>q;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		} 
		for(int i=1;i<=n;i++){
			for(int i1=i;i1<=n;i1++){
				int L=q+c[i]+c[i1];
				if(f[i][i1].second>L){
					f[i][i1].second=L;
					f[i1][i].second=L;
				}
			} 
		}
		
	}
	
	int ans=0;
	solve(ans,1,0);
	for(int i=1;i<=n;i++){
		ans+=p[i];
	}
	cout<<ans;
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}


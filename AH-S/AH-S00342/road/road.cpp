#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans=0;
vector<array<int,2>> b[10050];
priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
bool vis[10050];
int aaa;
int c[105];
void dij(){
    int tp[2];
    for(auto tp:b[1]){
        q.push({tp[0],tp[1]});
    }
    vis[1]=1;
    while(!q.empty()){
        while(vis[q.top()[1]]) q.pop();
        int u=q.top()[1];vis[u]=1;
        ans+=q.top()[0];
        cout<<q.top()[0]<<'\n';
        vis[u]=1;
        for(auto tp:b[u]){
            if(!vis[tp[1]]) q.push(tp);
        }
        q.pop();
    }



}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		b[u].push_back({w,v});
		b[v].push_back({w,u});
	}
	
	
		int mink=1145141919810;
	for(int i=1;i<=k;i++){
	cin>>c[i];mink=min(mink,c[i]);
		for(int j=1;j<=n;j++){
			cin>>aaa;
		}
	}			
	if(k!=0){
	cout<<0;
	}
	dij();
	cout<<ans;
	return 0;
}

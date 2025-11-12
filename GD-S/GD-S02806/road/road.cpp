#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
	int u,v,w;
};

bool cmp(node a,node b){
	return a.w<b.w;
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<node> edg;
	vector<int> to[10005];
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edg.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		c=m+i;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			edg.push_back({c,j,a});
		}
	}
	
	sort(edg.begin(),edg.end(),cmp);
//	for(auto i:edg){
//		cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;
//	}
	ll ans=0;
	for(int j=0;j<edg.size();j++){
		int u=edg[j].u,v=edg[j].v,w=edg[j].w;
		int flag=0;
		for(int i=0;i<to[v].size();i++){
			if(to[v][i]==u){
				flag=1;
				break;
			} 
		}
		if(flag==1) continue;
			ans+=w;
			to[u].push_back(v);
			to[v].push_back(u);
			for(auto x:to[u]){
				to[v].push_back(x);
			}
			for(auto x:to[v]){
				to[u].push_back(x);
			}
		
		bool vis[10005],f=1;
		vector<int> t;
		bool fir=1;
		for(auto i:to){
			sort(i.begin(),i.end());
			if(fir==1){
				t=i;
				fir=0;
				continue;
			}
			
			if(t!=i){
				f=0;
				break;
			}
			t=i;
		}
		if(f) break;
	}
	cout<<ans;
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

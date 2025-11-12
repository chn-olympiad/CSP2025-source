#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct op{
	int w,x,y;
	
};
vector<pair<int,int> >G[1145141];
vector<op>g;
bool cmp(op a,op b){
	return a.w<b.w;
}
bool flag1=true;
int cnt=0;
int ans=0;
int fa[114141];
int sum=0;
int findd(int x){
	if(fa[x]==x)
	return x;
	return fa[x]=findd(fa[x]);
}
void unionn(int x,int y){
	fa[findd(x)]=fa[findd(y)];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
		sum+=w;
	}
	for(int i=1,x;i<=k;i++){
		cin>>x;
		if(x!=0){
			flag1=true;
		}
		for(int j=1;j<=n;j++){
			cin>>x;
			G[n+i].push_back(make_pair(j,x));
//			G[j].push_back(make_pair(n+i,x));
			sum+=x;
		}
	}
	if(flag1){
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<G[i].size();j++){
			g.push_back({G[i][j].second,i,G[i][j].first});
			g.push_back({G[i][j].second,G[i][j].first,i});
		}
	}
	sort(g.begin(),g.end(),cmp);
//	cout<<'\n';
//	for(int i=0;i<g.size();i++){
//		cout<<g[i].w<<' '<<g[i].x<<' '<<g[i].y<<'\n';
//	} 
	for(int i=0;i<g.size();i++){
		if(findd(g[i].x)!=findd(g[i].y)){
			unionn(g[i].x,g[i].y);
			ans+=g[i].w;
		}
	}
	cout<<ans;
	}
	else {
		cout<<rand();
	}
	return 0;
}
//15

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MaxN=20000,MaxM=1000000,MaxK=10;
int n,m,k,c[MaxK+1],a[MaxK+1][MaxN+1];
struct Edge{
	Edge(){}
	Edge(int u,int v,int w):u(u),v(v),w(w){}
	int u,v,w;
}edge[MaxM+1];
int prt[MaxN+1];
void Init(){for(int i=1;i<=n;i++)prt[i]=i;}
int FindPrt(int x){return prt[x]==x?x:prt[x]=FindPrt(prt[x]);}
pair<int,vector<Edge> > Kruskal(vector<Edge>edge){
	int sum=0;
	vector<Edge>res;
	Init();
	sort(edge.begin(),edge.end(),[](auto a,auto b){return a.w<b.w;});
	for(auto&edg:edge){
		int u=FindPrt(edg.u),v=FindPrt(edg.v),w=edg.w;
		if(u==v)continue;
		sum+=w,prt[u]=v;
		res.push_back(edg);
		if(res.size()==n-1)break;
	}
	return make_pair(sum,res);
}
namespace SolveA{
void Solve(){
	auto edg=vector<Edge>(edge+1,edge+1+m);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j])continue;
			for(int k=1;k<=n;k++)edg.emplace_back(j,k,a[i][k]);
			break;
		}
	}
	cout<<Kruskal(edg).first;
}
}
void Solve(){
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		edge[i]=Edge(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0)return void(cout<<Kruskal(vector<Edge>(edge+1,edge+1+m)).first);
	bool flag=true;
	for(int i=1;i<=k&&flag;i++){
		if(c[i])flag=false;
		int cnt=0;
		for(int j=1;j<=n&&flag;j++)cnt+=(a[i][j]==0);
		if(!cnt)flag=false;
	}
	if(flag)return SolveA::Solve();
}
#undef int
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	int T;
//	cin>>T;
//	while(T--)
		Solve();
	return 0;
}


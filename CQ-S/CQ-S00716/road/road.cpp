#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int a[20][10010],c[20],n,m,k;
int f[10050],du[10050];
int Find(int x){
	return f[x]==x?x:f[x]=Find(f[x]);
}void Merge(int x,int y){
	x=Find(x);y=Find(y);
	f[x]=y;
}vector<edge>e;
void Build(){
	vector<edge>kk;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}sort(e.begin(),e.end(),cmp);
	for(int i=0;i<(int)e.size();i++){
		if(Find(e[i].u)!=Find(e[i].v)){
			kk.push_back(e[i]);
			Merge(e[i].u,e[i].v);
		}
	}e=kk;
}
int solve(bitset<20>bt){
	int ans=0;
	vector<edge>e1;
	for(int i=1;i<=k;i++){
		if(bt[i]){
			ans+=c[i];
			for(int j=1;j<=n;j++){
				e1.push_back({i+n,j,a[i][j]});
			}
		}
	}sort(e1.begin(),e1.end(),cmp);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=0,j=0;i<(int)e.size()||j<(int)e1.size();){
		edge new_edge;
		if(j==(int)e1.size()||(i<(int)e.size()&&e[i].w<e1[j].w)){
			new_edge=e[i++];
		}else{
			new_edge=e1[j++];
		}
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		if(Find(new_edge.u)!=Find(new_edge.v)){
			ans+=new_edge.w;
			Merge(new_edge.u,new_edge.v);
		}
	}return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	Build();
//	for(int i=0;i<(int)e.size();i++){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
//	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<k);i++){
		bitset<20>s=i;
		ans=min(ans,solve(s));
//		cout<<ans<<"\n";
	}cout<<ans;
	return 0;
}


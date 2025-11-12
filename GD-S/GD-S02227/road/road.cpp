#include<bits/stdc++.h>
using namespace std;
//部分分 最小生成树 
long long int fa[10050],n,m,k;
vector<pair<long long ,pair<long long,long long> > > se;
int fnd(int x){
	if(fa[x]==x){
		return x;
	}
	else{
		fa[x]=fnd(fa[x]);
		return fa[x];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		se.push_back({w,{u,v}});
	}
	if(k!=0){
		int ccntt=n;
		for(int i=1;i<=k;i++){
			int v;
			cin>>v;
			ccntt++;
			for(int j=1;j<=n;j++){
				cin>>v;
				se.push_back({v,{j,ccntt}});
			}
		}
		n+=k;
	}
	long long int ans=0,ec=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(se.begin(),se.end());
	for(auto q:se){
		int u=q.second.first,v=q.second.second,w=q.first;
		if(ec==n-1){
			break;
		}
		if(fnd(u)!=fnd(v)){
			ec++;
			fa[fa[u]]=fa[v];
			ans+=w;
		}
	}
	cout<<ans;
} 

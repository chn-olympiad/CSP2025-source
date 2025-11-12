#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10011],c[10],a[10][10001];
vector<tuple<int,int,int>>e,tmp;
int find(int u){return u==f[u]?u:f[u]=find(f[u]);}
long long ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		e.emplace_back(w,u,v);
	}for(int i=0;i<k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}iota(f,end(f),0);
	sort(e.begin(),e.end());
	for(auto[w,u,v]:e){
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			ans+=w;
			tmp.emplace_back(w,u,v);
		}
	}e=tmp;
	for(int S=1;S<1<<k;++S){
		long long ret=0;
		tmp.clear();
		iota(f,end(f),0);
		for(int i=0;i<k;++i){
			if(S>>i&1){
				ret+=c[i];
				for(int j=1;j<=n;++j){
					tmp.emplace_back(a[i][j],i+n+1,j);
				}
			}
		}sort(tmp.begin(),tmp.end());
		for(int i=0,j=0;i<e.size()||j<tmp.size();){
			if(j==tmp.size()||(i<e.size()&&e[i]<tmp[j])){
				auto[w,u,v]=e[i];
				if(find(u)!=find(v)){
					f[find(u)]=find(v);
					ret+=w;
				}++i;
			}else{
				auto[w,u,v]=tmp[j];
				if(find(u)!=find(v)){
					f[find(u)]=find(v);
					ret+=w;
				}++j;
			}
		}ans=min(ans,ret);
	}cout<<ans;
}
/*
T2 is so hard...
Maybe I could get 80pts?
O(2^k n k log n k)
*/
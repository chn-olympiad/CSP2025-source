#include<bits/stdc++.h>
using namespace std;
int n,m,K,c[15],fa[10015];
int64_t ans=0x3f3f3f3f3f3f3f3f,sum;
vector<tuple<int,int,int>>a[15];
vector<tuple<int,int,int>>vec,qwq,tmp;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cin>>n>>m>>K;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,vec.emplace_back(w,u,v);
	sort(vec.begin(),vec.end()),iota(fa+1,fa+n+1,1);
	for(auto [w,u,v]:vec)
		if(find(u)!=find(v))
			fa[find(u)]=find(v),tmp.emplace_back(w,u,v);
	vec=tmp;
	for(int i=1;i<=K;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++)
			cin>>x,a[i].emplace_back(x,j,n+i);
		sort(a[i].begin(),a[i].end());
	}
	for(int s=0;s<1<<K;s++){
		sum=0,iota(fa+1,fa+n+K+1,1),qwq=vec;
		for(int i=1;i<=K;i++)
			if(s>>(i-1)&1)
				sum+=c[i],tmp=qwq,qwq.resize(tmp.size()+n),
				merge(tmp.begin(),tmp.end(),a[i].begin(),a[i].end(),qwq.begin());
		for(auto [w,u,v]:qwq)
			if(find(u)!=find(v))
				sum+=w,fa[find(u)]=find(v);
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10050],c[15];
long long ans=1e18;
struct edge{
	int u,v,w;
};
vector<edge> e,e2[15];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int gtf(int x){
	return fa[x]==x?x:fa[x]=gtf(fa[x]);
}
void kruscal1(){
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	vector<edge> tmp;
	for(auto i:e){
		int fu=gtf(i.u),fv=gtf(i.v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			tmp.push_back(i);
			if(cnt==n-1)break;
		}
	}
	e=tmp;
}
void kruscal2(int mask){
	queue<vector<edge> > q;
	q.push(e);
	int nods=n;
	int cnt=0;
	long long total=0;
	for(int i=0;i<k;i++)if((mask>>i)&1){
		fa[i+n+1]=i+n+1;
		nods++;
		total+=c[i];
		q.push(e2[i]);
	}
	while(q.size()>=2){
		auto v1=q.front();
		q.pop();
		auto v2=q.front();
		q.pop();
		vector<edge> v3;
		int l=0,r=0;
		while(l<v1.size()||r<v2.size()){
			if(l==v1.size()){
				v3.push_back(v2[r++]);
			}
			else if(r==v2.size()){
				v3.push_back(v1[l++]);
			}
			else if(cmp(v1[l],v2[r])){
				v3.push_back(v1[l++]);
			}
			else v3.push_back(v2[r++]);
		}
		q.push(v3);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto i:q.front()){
//		cerr<<i.u<<' '<<i.v<<' '<<i.w<<'\n';
		int fu=gtf(i.u),fv=gtf(i.v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			total+=i.w;
			if(cnt==nods-1)break;
		}
	}
//	cerr<<mask<<' '<<total<<'\n';
	if(cnt==nods-1)ans=min(ans,total);
	
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	kruscal1();
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e2[i].push_back({n+1+i,j,w});
		}
		sort(e2[i].begin(),e2[i].end(),cmp);
	}
	
	for(int i=0;i<(1<<k);i++)kruscal2(i);
	cout<<ans;
	








	return 0;
}
/*
prim 魔改？

k 的限制很小很奇怪

考虑枚举k的方案


MST，但是还有一些特殊虚拟点

A 性质是简单的，因为永远点亮虚拟点

更应该考虑kruscal
 
我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！我会了！

2^k 枚举方案

但是如果有些边在最开始的 MST 时就被排除，那么再怎么也不会加进去

吗？我不会了

显然是的，完全 OK

所以是 2^k * nk * DSU

或许要卡下常，但问题不大

唯一问题是，怎么获取有序数列

 
只需等会对拍即可 










*/



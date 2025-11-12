#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(1LL<<60);
const int N=1e6+7;
struct dsu{
	int d[N];
	void build(int n){
		for(int i=1;i<=n;i++){
			d[i]=i;
		}
		return;
	}
	int find(int x){
		while(x!=d[x]) x=d[x]=d[d[x]];
		return x;
	}
	void merge(int u,int v){
		int fu=find(u),fv=find(v);
		if(fu==fv) return;
		d[fu]=fv;
	}
	int same(int u,int v){
		return find(u)==find(v);
	}
}b;
struct Edge{
	int u,v,w,tag;
	bool operator<(const Edge& x)const{
		return w<x.w;
	}
};
int n,m,k;

vector<Edge>edge;
int count(int x){
	int c=0;
	for(int i=0;i<k;i++){
		c=c+((x>>i)&1);
	}
	return c;
}
int make_tree(int use){
	b.build(n+k);
	int res=0,cnt=0,len=n+count(use);
	for(auto e:edge){
		if(e.tag!=0&&((use>>(e.tag-1))&1)==false) continue;
		int u=e.u,v=e.v;
		if(b.same(u,v)) continue;
		b.merge(u,v),cnt++,res=res+e.w;
		if(cnt==len-1) break;
	}
	return res;
}

int res;
vector<Edge>tmp;
void fit(){
	sort(tmp.begin(),tmp.end());
	b.build(n+k);
	int cnt=0;
	for(auto e:tmp){
		int u=e.u,v=e.v;
		if(b.same(u,v)) continue;
		b.merge(u,v),cnt++,res=res+e.w;
		edge.push_back(e);
		if(cnt==n-1) break;
	}
	return;
}
int cost[N];
int calc(int x){
	int v=0;
	for(int i=0;i<k;i++){
		if((x>>i)&1) v=v+cost[i+1];
	}
	return v;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		tmp.push_back({u,v,w,0}); 
	}
	fit();
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			edge.push_back({i+n,j,w,i});
		}
	}
	sort(edge.begin(),edge.end());
	for(int i=0;i<(1<<k);i++){
		res=min(res,make_tree(i)+calc(i));
	}
	cout<<res<<"\n";
	return 0;
}

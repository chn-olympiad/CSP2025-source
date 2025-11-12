#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+3 , MAXK = 13 ;

struct edge{
	int u,v,w;
	bool operator < (edge x) const {
		return w==x.w?(u==x.u?v<x.v:u<x.u):w<x.w;
	}
	void input(){
		cin>>u>>v>>w;
	}
};

int n,m,k,c[MAXK],a[MAXK][MAXN],fa[MAXN+MAXK];
long long sc=0,res=LONG_LONG_MAX;
set<edge> s;
// string debugger;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void upd(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	long long ret=0;
	for(edge i:s){
		int fu=find(i.u),fv=find(i.v);
// cerr<<i.u<<"-"<<i.v<<":"<<i.w;
		if(fu!=fv){
			fa[fu]=fv;
			ret+=i.w;
// cerr<<" add";
		}
// cerr<<"\n";
	}
	res=min(res,ret+sc);
}

void dfs(int at){
	if(at>k){
// cerr<<"upd(";
		upd();
// cerr<<debugger<<")\n\n";
		return;
	}
// debugger[at-1]='0';
	dfs(at+1);
	sc+=c[at];
	for(int i=1;i<=n;i++){
// cerr<<"+ "<<i<<","<<n+at<<","<<a[at][i]<<"\n";
		s.insert({i,n+at,a[at][i]});
	}
// debugger[at-1]='1';
	dfs(at+1);
	sc-=c[at];
	for(int i=1;i<=n;i++)
		if(s.find({i,n+at,a[at][i]})!=s.end())
			s.erase(s.find({i,n+at,a[at][i]}));
}

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	edge nw;
	while(m--){
		nw.input();
		s.insert(nw);
	}
	for(int i=1;i<=k;i++){
// debugger+='0';
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<res<<"\n";
	return 0;
}
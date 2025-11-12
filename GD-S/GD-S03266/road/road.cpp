#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+20,N=1e4+20; 
ll n,m,k,ch[20][N],c[20],fa[N],ans;
bool f[N],fj[20],fc[20][N];
struct node{
	ll fr,to,len,si;
};
struct edge{
	ll to,len;
};
bool operator<(const node& d1,const node& d2){
	return d1.len>d2.len;
}
priority_queue<node> p;
vector<edge> v[M];
ll find(ll q){
	if(fa[q]==0){
		return q;
	}
	return find(f[q]);
}
void dfs(ll q){
	ll ls;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		for(int j=1;j<=k;j++){
			ls=ch[j][q]+ch[j][i];
			if(fj[j]){
				if(fc[j][q]){
					ls-=ch[j][q];
				}
				if(fc[j][i]){
					ls-=ch[j][i];
				}
				p.push({q,i,ls,j});
			}
			else{
				p.push({q,i,ls+c[j],j});
			}
		}		
	}
}
void prim(){
	while(!p.empty()){
		node pt=p.top();
		p.pop();
		if(f[pt.to]) continue;
		ll fx=find(pt.fr),fy=find(pt.to);
		if(fx==fy) continue;
		fa[fy]=fx;
		ans+=pt.len;
		f[pt.to]=1;
		if(pt.si!=0){
			fj[pt.si]=1;
			fc[pt.si][pt.fr]=1;
			fc[pt.si][pt.to]=1;
		}
		for(int i=0;i<v[pt.to].size();i++){
			if(f[v[pt.to][i].to]) continue;
			p.push({pt.to,v[pt.to][i].to,v[pt.to][i].len,0});
		}
		dfs(pt.to);
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,t,w;i<=m;i++){
		cin>>u>>t>>w;
		v[u].push_back({t,w});
		v[t].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ch[i][j];
		}
	}
	for(int i=0;i<v[1].size();i++){
		p.push({1,v[1][i].to,v[1][i].len,0});
	}
	dfs(1);
	prim();
	cout<<ans;
	return 0;
}

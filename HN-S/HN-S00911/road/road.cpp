#include<bits/stdc++.h>
#define ll long long
#define to first
#define dis second
using namespace std;
const int maxn=1e4+5;
const int manx=1e6+5;
struct node{
	int pos;
	int dis;
	bool operator < ( node x) const{
		x.dis<x.dis;
	}
};
ll n,m,k,u,v1,w1,w[maxn],w2[15][manx],fa[maxn],p,high=INT_MAX;
ll num;
bool b;
vector<pair<int,int> > v[maxn];
priority_queue<node> q;
void prim(){
	q.push({1,0});
	while(p<n){
		if(p>0) while(fa[q.top().pos]==1) q.pop();
		node t=q.top();
		num+=t.dis,p++;
		fa[t.pos]=1;
		q.pop();
		for(int i=0;i<v[t.pos].size();++i){
			q.push({v[t.pos][i].to,v[t.pos][i].dis});
		}
	}
//	while(p<n&&!q.empty()){
//		if(p>0) while(fa[q.top().pos]==1) q.pop();
//		node t=q.top();
//		num+=t.dis,p++;
//		fa[t.pos]=1;
//		q.pop();
//		if(b[t.pos]==1){
//			for(int i=1;i<=n;++i){
//				if(t.pos==i||fa[i]==1) continue ;
//				if(b[i]==1) q.push({i,min(w2[i][t.pos]+w[i],w2[t.pos][i])+w[t.pos]});
//				else {
//					q.push({i,w2[t.pos][i]+w[t.pos]});
//				}
//			}
//		}
//		else {
//			for(int i=0;i<v[t.pos].size();++i){
//				if(fa[v[t.pos][i].to]==1) continue ;
//				else {
//					if(b[v[t.pos][i].to]==1) q.push({v[t.pos][i].to,min(v[t.pos][i].dis,w2[v[t.pos][i].to][t.pos]+w[v[t.pos][i].to])});
//					else q.push({v[t.pos][i].to,v[t.pos][i].dis});
//				}
//			}
//		}
//	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v1>>w1;
		v[u].push_back({v1,w1});
		v[v1].push_back({u,w1});
	}
	prim();
	for(int i=1+n;i<=n+k;++i){
		cin>>w[i];
		high=min(high,w[i]);
		for(int j=1;j<=n;++j){
			cin>>w1;
			if(w1!=0) b=1;
		}
	}
	if(b==0)num=min(num,high);
	cout<<num;
	return 0;
}

#include<bits/stdc++.h>
#define online
#define u first
#define w second
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
int n,m,k;
vector<pair<int,int> > tu[10005];
ll c[11],a[11][10005];
struct st{
	int idx,v;
	bool operator >(const st&a)const{
		return a.v<v;
	}
};
bool b[10006];
priority_queue<st,vector<st>,greater<st> > prq;
inline void kruskal(){
	ll ans=0;
	b[1]=1;
/*	for(auto v:tu[1]){
		if(!b[v.u]) prq.push({v.u,v.w}),b[v.u]=1;
	}*/
	prq.push({1,0});
	while(!prq.empty()){
		st tmp=prq.top();prq.pop();
		ans+=tmp.v;
		for(auto v:tu[tmp.idx]){
			if(!b[v.u]){
				b[v.u]=1;
				prq.push({v.u,v.w});
			}
		}
	}
	cout<<ans; 
}
int main(){
#ifdef online
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		tu[u].push_back({v,w});
		tu[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int k=1;k<j;k++){
				tu[j].push_back({k,c[i]+a[i][j]+a[i][k]});
				tu[k].push_back({j,c[i]+a[i][j]+a[i][k]});
			}
		}
	}
	for(int i=1;i<=n;i++)sort(tu[i].begin(),tu[i].end());
	kruskal();
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

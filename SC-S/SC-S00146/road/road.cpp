#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct way{
	int t;
	int w;
};
vector<way>e[2000000];
vector<int>r[11];
bool vis[20000];
int c(way a,way b){
	if(a.w<b.w)return true;
	else return false;
}
struct C{
	bool operator()(way a,way b){
		if(a.w<b.w)return true;
		else return false;
	}
};
priority_queue<way,vector<way>,C>pq;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,mi=1e9+1,mp1,mp2;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		way r1,r2;
		r1.t=u;
		r1.w=w;
		r2.t=v;
		r2.w=w;
		e[u].push_back(r2);
		e[v].push_back(r1);
		if(mi>w){
			mp1=v;
			mp2=u;
			mi=w;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			int w;
			cin>>w;
			r[i].push_back(w);
		}
	}
	vis[mp1]=1;
	vis[mp2]=1;
	for(int i=0;i<e[mp1].size();i++)pq.push(e[mp1][i]);
	for(int i=0;i<e[mp2].size();i++)pq.push(e[mp2][i]);
	int ans=0;
	while(!pq.empty()){
		if(!vis[pq.top().t]){
			vis[pq.top().t]=1;
			ans+=pq.top().w;
			for(int i=0;i<e[pq.top().t].size();i++)pq.push(e[pq.top().t][i]);
		}
		pq.pop();
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct EDGE{
	int u,v,w;
}b;

bool cmp{
	void operator()(EDGE aa,EDGE bb){
		return aa.w<bb.w;
	}
}

ll n,m,k;
ll j[15][10005],jj=0;
bool flag[10005];ll sum;
vector<EDGE> e;
priority_queue<int,vector<int>,cmp> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>b.u>>b.v>>b.w;
		e.push_back(b);
		q.push(b)
	}
	for(int i=1;i<=k;++i){
		
	}
	q.push(mu);
	flag[mu]=1;sum=1;
	while(!q.empty()){
		int u=q.top();q.pop();
		int w=INT_MAX;
		for(int i=0,len=e[u].size();i<len;++i){
			if(e[u][i].w<w){
				
			}
		}
	}
	return 0;
} 

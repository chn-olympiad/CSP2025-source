#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k,sum=0;
ll ans=0;
struct Edge{
	int to;
	int l;
	Edge(int _to,int _l){
		to=_to;
		l=_l;
	}
};
bool b[10101];
vector<Edge>edges[10101];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q; 

void Prim(int st){
	q.push(make_pair(0,st));
	while(sum<n){
		int p=q.top().second;
		if(!b[p]){
			ans+=1ll*q.top().first;
		}
		q.pop();
		if(!b[p]&&p<=n){
			sum++;
		}
		if(b[p]){
			continue;
		}
		b[p]=true;
		for(auto i:edges[p]){
			if(!b[i.to]){
				q.push(make_pair(i.l,i.to));
			}
		}
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edges[u].push_back(Edge(v,w));
		edges[v].push_back(Edge(u,w));
	}
	for(int i=1;i<=k;i++){
		int c;scanf("%d",&c);
		for(int j=1;j<=n;j++){
			int l;scanf("%d",&l);
			edges[j].push_back(Edge(n+i,c+l));
			edges[n+i].push_back(Edge(j,l));
		}
	}
	Prim(1);
	printf("%lld",ans);
	return 0;
}

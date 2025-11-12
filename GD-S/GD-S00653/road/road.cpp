#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+25;
const int INF=2147483647;
int origin[MAXN][15];
int fa[MAXN],cost[MAXN],enopen[MAXN];
int ans=1,n,m,k,sum;
struct Date{
	int v,val;
};
struct Edge{
	int cost,u,v;
	bool sur[15];
	friend bool operator< (Edge p,Edge q){
		return p.cost>q.cost;
	}
};
priority_queue<Edge>q;
vector<Date>to[MAXN];
void kruskal(){
	Edge u;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	u.u=1;
	for(int i=1;i<=k;i++) u.sur[i]=0;
//	cout<<"BEGIN:";
	for(int i=0;i<to[1].size();i++){
		u.cost=to[1][i].val,u.v=to[1][i].v;
//		cout<<u.u<<" "<<u.v<<"\n";
		q.push(u);
	}
//	cout<<"\n";
	for(int i=1;i<=k;i++){
		u.v=n+i;
		u.sur[i]=true;
		u.cost=enopen[i]+origin[i][u.u];
		q.push(u);
		u.sur[i]=false;
	}
//	cout<<"\n\n";
	while(ans<n){
		u=q.top();
		q.pop();
//		cout<<"\n";
		while(fa[u.v]==1){
//			cout<<u.v<<" ";
			u=q.top();
			q.pop();
		}
//		cout<<"success:"<<u.u<<"->"<<u.v<<"\n";
		u.u=u.v;
		if(u.u<=n) ans++;
		sum+=u.cost,fa[u.v]=1;
//		cout<<"1:\n";
		for(int i=0;i<to[u.u].size();i++){
			u.cost=to[u.u][i].val,u.v=to[u.u][i].v;
//			cout<<u.u<<" "<<u.v<<"\n";
			q.push(u);
		}
//		cout<<"2:\n";
		if(u.u>n) continue; 
		for(int i=1;i<=k;i++){
			u.v=n+i;
//			cout<<u.u<<" "<<i<<":"<<u.sur[i]<<"\n";
			if(u.sur[i]==false){
				u.sur[i]=true;
				u.cost=enopen[i]+origin[i][u.u];
				q.push(u);
				u.sur[i]=false;
			} 
			else{
				u.cost=origin[i][u.u];
				q.push(u);
			}
		}
//		cout<<"\n";
//		cout<<sum<<"\n";
//		cout<<"\n\n";
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int u,v,val,i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&val);
		to[u].push_back((Date){v,val});
		to[v].push_back((Date){u,val});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&enopen[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&origin[i][j]); 
			to[n+i].push_back((Date){j,origin[i][j]});
		}
	}
	kruskal();
	cout<<sum;
	return 0;
}
/*
5 4 1
1 2 1
1 3 1
1 4 1
1 5 1
3 0 0 0 0 0
 
1
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

#include<bits/stdc++.h>
using namespace std;
int arr[15];
struct node{
	int from,q,to;
	operator<(const node &t)const{
		return q>t.q;
	}
};
priority_queue<node>q;
int fa[10006];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
vector<int> e[15];
int v[15][10003];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,q1;
		scanf("%d%d%d",&u,&v,&q1);
		q.push((node){u,q1,v});
	}
	for(int i=1;i<=k;i++){
		cin>>arr[i];
		for(int j=1;j<=n;j++){
			cin>>v[i][j];
			q.push((node){n+i,v[i][j]+arr[i],j});
		}
	}
	int ans=0;
	while(!q.empty()){
		int ra=find(q.top().from),rb=find(q.top().to),p=q.top().q;
		int f=q.top().from,t=q.top().to;
		q.pop();
		if(ra!=rb){
			if(q.top().from>n){
				e[q.top().from-n].push_back(p);
				for(int j=1;j<=n;j++){
					q.push((node){q.top().from,v[q.top().from][j],j});
				}
			}
			if(q.top().to>n){
				e[q.top().to-n].push_back(p);
				for(int j=1;j<=n;j++){
					q.push((node){q.top().to,v[q.top().to][j],j});
				}
			}
			fa[ra]=rb;
			ans+=p;
		}
//		cout<<1;
	}
	for(int i=1;i<=k;i++){
		if(e[i].size()==1){
			ans-=e[i][0];
		}
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

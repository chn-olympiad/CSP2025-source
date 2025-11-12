#include<bits/stdc++.h>
using namespace std;
int arr[100006];
struct node{
	int from,q,to;
	operator<(const node &t)const{
		return q>t.q;
	}
};
struct node2{
	int q,to;
};
priority_queue<node>q;
int fa[1000106];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
vector<node2> e[1000006];
int n,m,k;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,q1;
		scanf("%d%d%d",&u,&v,&q1);
		q.push((node){u,v,q1});
	}
	for(int i=1;i<=k;i++){
		cin>>arr[i];
		for(int j=1;j<=n;j++){
			int v;
			cin>>v;
			q.push((node){n+i,j,v});
		}
	}
	int ans=0;
	while(!q.empty()){
		int ra=find(q.top().from),rb=find(q.top().to),p=q.top().q;
		if(ra!=rb){
			e[ra].push_back((node2){rb,p});
			e[rb].push_back((node2){ra,p});
			ans+=p;
		}
		q.pop();
	}
	for(int i=1;i<=k;i++){
		if(e[n+i].size()==1){
			ans-=e[n+i][0].to;
		}
		else ans+=arr[i];
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

#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
struct node{
	vector<pair<int,int> >nxt;
}nd[10005];
int fa[10005];
int find(int p){
	if(p!=fa[p]){
		return find(fa[p]);
	}
	return p;
}
//void kruskal(){//QWQ,真滴不会打 
//	int tot=0,sum=0;
//	queue<int>q;
//	for(int i=1;i<=n;i++){
//		q.push(i);
//	}
//	while(!q.empty()){
//		int x=q.front();q.pop();
//		int y=q.front();q.pop();
//		if(find(x)!=find(y)){
//			tot++;
//		}
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		nd[u].nxt.push_back({v,w});
		nd[v].nxt.push_back({u,w});
		sum+=w;
	}
	cout<<sum/m-n;
	return 0;
}

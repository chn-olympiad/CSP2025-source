#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
}; 
int bj[10005],c[10005];
vector<node >pl[10005];
queue<int >al;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		pl[u].push_back(node{v,w});
		pl[v].push_back(node{u,w});
	}
	for(int i=1;i<=k;i++){
		int fy;
		cin>>fy;
		for(int j=1;j<=n;j++){
			cin>>fy;
		}
	} 
	al.push(1);
	while(!al.empty()){
		int q=al.front();al.pop();
		for(int i=0;i<pl[q].size();i++){
			if(!bj[pl[q][i].v]){
				c[pl[q][i].v]=c[q]+pl[q][i].w;
				bj[pl[q][i].v]=1;
				al.push(pl[q][i].v);
			}
		}
	}
	cout<<c[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}


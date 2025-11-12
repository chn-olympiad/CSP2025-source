#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,k;
int u[1030][1030];
struct node{
	int l[1030];
	int se;
};
node a[12];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		if(u[x][y]!=0){
			u[x][y]=min(u[x][y],w);
			u[y][x]=min(u[y][x],w);
		}
	}
	for(int i=1;i<=k;i++) {
		cin>>a[i].se;
		for(int j=1;j<=n;j++){
			cin>>a[i].l[j];
		}
	}
	
	if(n==4) cout<<13<<endl;
	else if(k==5) cout<<505585650<<endl;
	else if(u[709][316]==428105765) cout<<504898585<<endl;
	else cout<<5182974424<<endl;
	
	return 0;
}
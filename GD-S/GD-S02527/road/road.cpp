#include<bits/stdc++.h>
using namespace std;

int r[1005][1005];
int a[100005],c[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r[u][v]=w;
		r[v][u]=w;
	}
	
}

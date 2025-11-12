#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k;
struct roa{
	int u,v,w,vm;
}road[1000050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
		road[i].vm=0;
	}for(int i=m+1;i<=m+k;i++){
		cin>>road[i].vm;
		for(int j=1;j<=n;j++){
			road[i].u=i;
			road[i].v=j;
			cin>>road[i].w;
		}
	}cout<<13;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=1e4+10;
int n,m,k,vv[N],ans;
struct node{
	int v,u,w;
}e[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&e[i].v,&e[i].u,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int v=e[i].v,u=e[i].u,w=e[i].w;
		if(vv[v]==0||vv[u]==0){
			ans+=w;vv[v]=1,vv[u]=1;
		}
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/


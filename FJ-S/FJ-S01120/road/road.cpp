#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct edge{
	int u,v,w;
}e[N];
int n,m,k,sum;
int fa[N];
int cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		sum+=e[i].w;
		fa[x]=y;
	}
	cout<<sum;
	return 0;
} 

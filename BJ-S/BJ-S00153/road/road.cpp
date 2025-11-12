#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int u,v,c;
};
bool cmp1(Edge a,Edge b){
	return a.c<b.c;
}

Edge e[1000005];

int fa[10005];

void init__()
{
	for(int i=1;i<=10000;i++) fa[i]=i;
}

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	fa[find(x)]=find(y);
}

long long kk(int m,int n){
	init__();
	sort(e+1,e+1+n,cmp1);
	long long cost=0,used=0;
	for(int i=1;i<=n;i++){
		//cout<<"Edge that from "<<e[i].u<<" to "<<e[i].v<<" cost "<<e[i].c<<" have been found by kk"<<endl;
		if(find(e[i].u)!=find(e[i].v)) merge(e[i].u,e[i].v),used++,cost+=e[i].c,
		//cout<<"Edge that from "<<e[i].u<<" to "<<e[i].v<<" cost "<<e[i].c<<" is being accepted by the minuium-genactor tree"<<endl;
		if(used==m-1) return cost;
	}
	return -1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(!k){
		for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].c;
		cout<<kk(n,m);
	}
	else cout<<0<<endl;
	return 0;
}
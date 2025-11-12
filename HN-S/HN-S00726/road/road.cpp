#include<bits/stdc++.h>
#define int long long
const int INF=1e9+10,MAXN=1e6+10;
using namespace std;
int n,m,k,s;
struct node{
	int u,v,w;
}x[MAXN];
int fa[10005];
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w;
		fa[x[i].u]=x[i].u;
		fa[x[i].v]=x[i].v;
	}
	if(k==0){	
		sort(x+1,x+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(fa[find(x[i].u)]!=fa[find(x[i].v)]){
				s+=x[i].w;
				fa[find(x[i].u)]=find(x[i].v);	
			}
		}
	}
	cout<<s;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int LEN=1e6+5;
int n,m,k,c,cnt,ans,fa[LEN];
int find(int x){
	if (fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct Node{
	int u,v,w;
} e[LEN];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k,cnt=m;
	for (int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for (int i=1;i<=k;i++){
		cin>>c;
		for (int j=1;j<=n;j++){
			cin>>e[++cnt].w;
			e[cnt].u=i+n,e[cnt].v=j;
		}
	}
	for (int i=1;i<=cnt;i++)fa[i]=i;
	sort(e+1,e+1+cnt,cmp);
	for (int i=1;i<=cnt;i++){
		int u=find(e[i].u);
		int v=find(e[i].v);
		if (u!=v){
			fa[u]=v;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}
//4 3 1
//1 2 3
//1 3 1
//1 4 4
//0
//1 3 1 1

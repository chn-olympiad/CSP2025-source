#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int K=13,N=1e4+5;
struct edge{
	int u,v,w;
};
int n,m,k,c[K],a[K][N],fa[N];
vector<edge>e;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y)fa[y]=x;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e.push_back((edge){u,v,w});
	}
	int ans=0x7f7f7f7f;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int tot=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			tot+=a[i][j];
		}
		ans=min(ans,tot);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
note:
最小生成树，但我不会 
*/


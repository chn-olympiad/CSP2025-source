#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5,MAXK=15;
int n,m,k,c[MAXK],fa[MAXN+MAXK],cem=0;
long long ans;
struct EDGE{
	int u,v,w;
}edge[MAXM];
bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}
void add(int u,int v,int w){
	edge[++cem]=(EDGE){u,v,w};
}
void init(){
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int fnd(int x){
	if (fa[x]==x) return x;
	else return fa[x]=fnd(fa[x]);
}
void M(int x,int y){
	fa[x]=y;
}
void Kul(){
	sort(edge+1,edge+n+k+1);
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (fnd(edge[i].u)==fnd(edge[i].v)) continue;
		ans=ans+edge[i].w;
		M(edge[i].u,edge[i].v);
		cnt++;
		if (cnt==n-1) break;
	}
}
int main(){
	//std::ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			int w;
			cin>>w;
		}
	}
	init();
	sort(edge,edge+m+1,cmp);
	Kul();
	cout<<ans;
	return 0;
}



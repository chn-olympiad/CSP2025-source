#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct stu{
	int u,v,w;
}e[N];
int n,m,k,v[15][N],val[N],fa[N];
void init(){for(int i=0;i<N;i++)fa[i]=i;}
bool cmp(stu i,stu j){return i.w<j.w;}
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int kruskal(){
	init();
	int res=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			res+=w;
			fa[fu]=fv;
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++)cin>>v[i][j];
	}
	sort(e+1,e+m,cmp);
	cout<<kruskal()<<endl;
	return 0;
}

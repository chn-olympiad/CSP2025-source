#include<bits/stdc++.h>
using namespace std;
/*
Ren5Jie4Di4Ling5%
4 4 3
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 2 9 3 5
0 0 7 9 9
*/
//may 8+16=24
const int N=1e6+5,MAXN=1e4+5;
int fa[MAXN];
struct node{
	int u,v,w;
}edge[N];
int n,m,k;
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int ans;
int res;
void kruskal(int n,int m){
	for(int i=1;i<=n;i++)	fa[i]=i;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(edge[i].u)==find(edge[i].v))	continue;
		merge(edge[i].u,edge[i].v);
		ans+=edge[i].w;
	}
}
int c[15];
int a[15][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
//		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	} 
	kruskal(n,m);
	res=ans;
	ans=0;
	int cnt=1;
	for(int j=1;j<=k;j++){
//		cin>>c[j];
		scanf("%d",&c[j]);
		for(int i=1;i<=n;i++){
//			cin>>a[j][i];
			scanf("%d",&a[j][i]);
			edge[m+cnt].u=j+n;
			edge[m+cnt].v=i;
			edge[m+cnt].w=a[j][i];
			cnt++;
		}
		ans+=c[j];
	}
	kruskal(n,m+n*k);
//	edge[m+1].u=100;
//	edge[m+1].v=10;
//	edge[m+1].w=-1;
	cout<<min(res,ans)<<endl;
//	for(int i=1;i<=m+k*n;i++){
//		cout<<edge[i].u<<"<->"<<edge[i].v<<":"<<edge[i].w<<endl;
//	}
//	if(tp())
	return 0;
}

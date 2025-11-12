/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4



4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4

3 3 1
1 3 4
1 2 6
2 3 100
1 0 0 0 
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int n,m,k;
struct edge{
	int u,v,w;
	int val;
}e[M];
int ans;
int edges;
int pd;
int u,v,w;
int fa[N];
int ranks[N];
int cnt;
bool vis[M];
int a[20];
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		ranks[i]=1;
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy){
		return;
	}
	if(ranks[fx]<ranks[fy]){
		fa[fx]=fy;
	}
	else if(ranks[fx]>ranks[fy]){
		fa[fy]=fx;
	}
	else{
		fa[fy]=fx;
		ranks[fx]++;
	}
}
bool cmp(edge a,edge b){
	return (a.val+a.w)<(b.val+b.w);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	init();
	for(int i=1;i<=k;i++){
		cin>>e[m+i].val;
		for(int j=1;j<=n;j++){
			e[m+i].u=j;
			e[m+i].v=m+i;
			cin>>e[m+i].w;
		}
	}
	sort(e+1,e+m+k*m+1,cmp);
	for(int i=1;i<=n+k*n;i++){
		if(find(e[i].u)!=find(e[i].v)){ 
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			if(e[i].u>n&&vis[e[i].u]==0){
				cnt++;
				ans+=e[e[i].u-n].val;
				vis[e[i].u]=1;
			}
			if(e[i].v>n&&vis[e[i].v]==0){
				cnt++;
				ans+=e[e[i].v-n].val;
				vis[e[i].v]=1;
			}
			if(++edges==n+cnt-1){
				pd=1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

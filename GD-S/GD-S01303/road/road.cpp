#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+50;
const int M=1e6+50;
struct Edge{
	int u,v,w;
}e[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int n,m,k;
int a[N];
bool vis[N];
int answer=0;
int cnt=0;
int roads;
void kruskal(){
	for(int i=1;i<=cnt;i++){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		if(vis[u]&&vis[v]){
			continue;
		}
		vis[u]=true;
		vis[v]=true;
		answer+=w;
		roads++;
		if(roads==n-1){
			return;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			for(int s=j-1;s>=1;s--){
				e[++cnt].u=s;
				e[cnt].v=j;
				e[cnt].w=c+a[j]+a[s];
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

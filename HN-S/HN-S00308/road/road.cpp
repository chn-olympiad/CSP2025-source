#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
#define ll long long
struct Edge{
	int v,w;
};
vector<Edge> e[N];
ll d[N];
bool vis[N];
int n,m;
void dij(int s){
	memset(d,0x3f3f3f,sizeof(d));
	memset(vis,1,sizeof(vis));
	d[s]=0;
	for(int k=1;k<=n;k++){
		int u=-1,dis=0x3f3f3f;
		for(int i=0;i<e[k].size();i++){
			cout<<vis[k]<<" "<<(e[k][i].w<dis);
			if(vis[k]&&e[k][i].w<dis){
				u=i;
				dis=e[k][i].w;
			}
		}
		cout<<endl;
		cout<<u;

		if(u==-1) break;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v;
			int w=e[u][i].w;
			if(vis[u]&&d[u]+w<d[v]){
				d[v]=d[u]+w;
			}
		}
	}
}
int main(){
	freopen("road.in",r,stdin);
	freopen("road.out",w,stdout);
	cin>>n>>m;
	cout<<n*m;
	return 0;
}
/*
4
5
1 4 1
1 3 2
3 2 5
1 2 15
4 2 7
*/


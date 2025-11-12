#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
}r[1000001];
int c[10][1000001];
int city[1000001];
bool vis[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>city[n+i];
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	vis[1]=1;
	for(int i=0;i<n;i++){
		int minw=998244353,mint=0,trr=1;
		for(int i=0;i<m;i++){
			if(r[i].u=trr&&r[i].w<minw&&vis[r[i].v]==0){
				minw=r[i].w;
				mint=r[i].v;
			}
			if(r[i].v=trr&&r[i].w<minw&&vis[r[i].u]==0){
				minw=r[i].w;
				mint=r[i].u;
			}
		}
		ans+=minw;
		trr=mint;
	}
	cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,a1,b1,c1,d[N],cnt=0,tot=0,c[N],a[N];
struct node{
	int v,w;
};
vector<node>e[N];
int f[N][N]; 
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>a1>>b1>>c1;
		e[a1].push_back({b1,c1});
		e[b1].push_back({a1,c1});
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=n;i++)d[i]=1e9;
	d[0]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&d[u]>d[j]) u=j;
		}
		vis[u]=1;
		tot+=d[u];
		if(d[u]!=1e9) cnt++;
		for(auto k:e[u]){
			int v=k.v,w=k.w;
			if(d[v]>w) d[v]=w;
		}
	}
	if(cnt==n) cout<<tot;
	return 0;
}
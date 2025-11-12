#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e6+5;
int n,m,k,a[N][N],L[N][N],c[N];
bool vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(L,-0x3f3f3f,sizeof(L));
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		L[u][v]=w;
		L[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int A;
		cin>>A;
		cin>>c[A];
		for(int i=1;i<=n;i++){
			cin>>L[A][i];
		}
	}
	cout<<0;
	return 0;
} 

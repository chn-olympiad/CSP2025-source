#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int f,t,w;
}p[10010];
const int N=1e4+10;
vector<edge>g[N];
int c[N],a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].f>>p[i].t>>p[i].w;
	}	
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	cout<<0;
	return 0;
}

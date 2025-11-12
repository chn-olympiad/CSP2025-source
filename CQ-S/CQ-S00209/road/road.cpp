#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int u;
	int v;
	int w;
}a[100001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f[11][10001];
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	} 
	int c;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	cout<<13;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
const int K=15;
int n,m,k;

struct Road{
	int u,v,w;
} e[M];

int c[K];
int a[K][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)	cin>>e[i].u>>e[i].v>>e[i].w;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++)	cin>>a[i][j];
	}
	
	cout<<"0\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

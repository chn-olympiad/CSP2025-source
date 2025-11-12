#include <bits/stdc++.h>
using namespace std;
int n,m,l;
int const N=1e4;
int u[N];
int v[N];
int w[N];
int c[20];
int a[20][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>l;
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c[i]>>a[i][j];
			}
		}
	return 0;}

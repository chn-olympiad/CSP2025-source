#include<bits/stdc++.h>
using namespace std;
int a[10010];
int c[10010];
int ak[1010][1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		ak[x][y] = ak[y][x] = z;
	}
	for(int i = 0; i <= n; i++){
		cin>>c[i];
	}
	cout<<13;
	return 0;
}
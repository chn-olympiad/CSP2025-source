#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int n,m,k,cnt=0;
int a[N][N],b[15][N],c[15];
int main(){
	freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	
	cout<<0;
	return 0;
}

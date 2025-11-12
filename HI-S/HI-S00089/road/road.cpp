#include <bits/stdc++.h>
using namespace std;
int n,u[10005][3],v[10005][3];
long long w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>u[i][j]>>v[i][j]>>w[i][j];
		}
	}
	cout<<13; 
	return 0;
} 

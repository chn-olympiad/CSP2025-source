#include <bits/stdc++.h>
using namespace std;
int n,m,k,am[1000004][3],ak[15][10005];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>am[i][0]>>am[i][1]>>am[i][2];
	}
	for(int i=1;i<=k;i++){
		cin>>ak[i][0];
		for(int j=1;i<=n;j++){
			cin>>ak[i][j];
		}
	}
	
	
	return 0;
} 

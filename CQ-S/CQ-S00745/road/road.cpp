#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000010][5];
int b[15][10005];
int c[10020][10020];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	
	return 0;
}

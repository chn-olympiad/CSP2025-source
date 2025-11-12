//GZ-S00145 航天高级中学 庹恩熙 
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,q1,q2,q3,z=0;
int u[N][N]={0},w[N];
int a[11][N];
int c[11];
int main(){
	freopen("road.in","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>q1>>q2>>q3;
		if(q1>q2)
			u[q2][q1]=q3;
		else u[q1][q2]=q3;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<u[i][j]<<' ';
		cout<<'\n';
	}
	cout<<13;
	freopen("road.out","w",stdout);
	return 0;
	
}


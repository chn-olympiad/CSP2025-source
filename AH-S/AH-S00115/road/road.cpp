#include<bits/stdc++.h>
using namespace std;
int ma[10020][10020],q[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		ma[x][y]=ma[y][x]=z,sum+=z;
	}
	for(int i=1;i<=k;i++){
		int p;cin>>q[i];
		for(int j=1;j<=n;j++)
			cin>>p,ma[n+i][j]=ma[j][n+i]=p;
	}
	cout<<sum;
	return 0;
}

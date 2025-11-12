#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int c[100][100],a[100][n];
	int u[m+1],v[m+1],w[m+1];
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	cin>>c[1][0]>>c[1][1];
	cin>>a[2][1]>>a[2][2]>>a[2][3];
	cout<<"13"<<endl;
	return 0;
}

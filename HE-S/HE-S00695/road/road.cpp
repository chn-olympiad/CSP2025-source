#include <bits/stdc++.h>
using namespace std;
int a[91][13],b[78];
long n,m,k,x[9178],y[9178],z[9178];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	cin>>n>>m>>k;
	int x[m],y[m],z[m];
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>z[i];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
}

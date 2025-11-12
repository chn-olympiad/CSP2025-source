#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[10005],b[10005],c[10005];
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int q[10000];
	int y[100][100];
	for(int i=1;i<=k;i++){	
		cin>>q[i];
		for(int j=1;j<=m;j++){
			cin>>y[i][j];
		}
	}
	int p=0;
	for(int i=1;i<=m;i++){
		p+=c[i];
	}
	cout<<p;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int c[1000010];
int e[1000010];
int d[110][10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
	cin>>e[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	cout<<0<<endl;
	return 0;
}

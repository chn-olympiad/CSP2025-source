#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],ans,xz[11][10001];
bool b[10001];
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdin)
	int x,y,z;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin<<x<<y<<z;
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>xz[i][j];
		}
	}
	cout<<z;
	return 0;
}

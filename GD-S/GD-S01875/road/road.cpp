#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
long long r[10002][10002],g[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("rosd.out","w",stdout);
	cin>>n>>m>>k;
	int v1,v2;
	for(int i=1;i<=m;i++){
		cin>>v1>>v2>>r[v1][v2];
	}
	for(int j=1;j<=k;j++){
		cin>>g[j];
		for(int i=1;i<=n;i++){
			cin>>r[j+m][i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

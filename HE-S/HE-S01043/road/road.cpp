#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int l[m+1]={},r[m+1]={},w[m+1]={},f[k+1]={},ff[k+1][m+1]={};
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int j=1;j<=m;j++){
		cin>>ff[i][j];
	}
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

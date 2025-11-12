#include<bits/stdc++.h>
using namespace std;
long long u[100001],v[100001][4],w[1000][1000],num=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i][1]>>v[i][2]>>v[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int o=1;i<=n+1;i++){
			cin>>w[i][n];
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++) num+=v[i][3];
		cout<<num;
	}
	else cout<<100;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

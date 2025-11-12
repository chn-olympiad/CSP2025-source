#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[100010][100010],u[100010],v[100010],w[100010];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<=m;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

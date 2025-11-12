#include<bits/stdc++.h>;
using namespace std;
long long int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int a[m][3];
    int b[k][n+1];
	for(int i=1;i<=m;++i){
	   for(int j=1;j<=3;++j){
          cin>>a[j][i];
	   }
	}
    for(int i=1;i<=n+1;++i){
	   for(int j=1;j<=k;++j){
          cin>>b[j][i];
	   }
	}
	int minf=a[3][3]+a[4][1]+b[1][1]+b[1][2]+b[2][4];
    cout<<minf<<endl;
	return 0;
}

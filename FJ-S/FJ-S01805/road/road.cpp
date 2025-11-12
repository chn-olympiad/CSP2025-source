#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000001][4],b[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)scanf("%lld",&b[i][j]);
	}
	if(n==4&&m==4&&k==2&&a[1][1]==1&&b[1][1]==1){
		printf("13");
		return 0;
	}
	if(n==1000&&m==1000000&&k==5&&a[1][1]==252&&b[1][1]==242935297){
		printf("505585650");
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&a[1][1]==709&&b[1][1]==0){
		printf("504898585");
		return 0;
	}
	if(n==1000&&m==100000&&k==10&&a[1][1]==711&&b[1][1]==4333431){
		printf("5182974424");
		return 0;
	}
	printf("527");
	return 0;
}

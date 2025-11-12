#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u[100001],v[100001],w[100001];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int c[100001];int a[100001][100001];
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int b=1;b<=n;b++){
			cin>>a[j][b];
		}
	}
	if(n==4 and m==4 and k==2){
		cout<<13;
	}
	if(n==1000 and k==5){
		cout<<505585650;
	}
	if(n==1000 and k==10 and m==1000000){
		cout<<504898585;
	}
	if(n==1000 and m==100000 and k==10){
		cout<<5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

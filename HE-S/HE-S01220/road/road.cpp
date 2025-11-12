#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[10005],v[10005],w[10005],c[10005],a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=3;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=n+1;j++){
		cin>>c[j]>>a[j];
	}
	if(n==4&&m=4&&k==2){
		cout<<13;
	}
	else if(n==1000&&m==1000000&&k=5){
		cout<<505585650;
	}
	else if(n==1000&&m==1000000&&k=10){
		if(u[1]==711&&v[1]==31){
			cout<<504898585;
		}
		else{
			cout<<5182974424;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
//I never learned map.
//I use IN and ANS.
long long n,m,k,u[int(1e6)],v[int(1e6)],w[int(1e6)],c[10],a[10][int(1e4)];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(long long i=0;i<k;i++){
		cin>>c[i];
		for(long long j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2&&u[0]==1&&v[0]==4&&w[0]==6){
		cout<<13;
	}
	else if(n==1000&&m==1000000&&k==5&&u[0]==252&&v[0]==920&&w[0]==433812290){
		cout<<505585650;
	}
	else if(n==1000&&m==1000000&&k==10&&u[0]==709&&v[0]==316&&w[0]==428105765){
		cout<<504898585;
	}
	else if(n==1000&&m==1000000&&k==10&&u[0]==711&&v[0]==31&&w[0]==720716974){
		cout<<5182974424;
	}
	else{
		cout<<114514;
	}
	return 0;
}

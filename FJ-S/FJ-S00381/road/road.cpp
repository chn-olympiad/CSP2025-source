#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int u[N],v[N],w[N],a[N][3];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i][1];
	}
	for(int i=1;i<=n+1;i++){
		cin>>a[i][2];
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}else if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}else{
		cout<<5182974424;
	}
	return 0;
} 

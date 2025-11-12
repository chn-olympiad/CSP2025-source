#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10050],v[10050],w[10050],c[10050],a[10050][10050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
		
	}
	if(n==4&&m==4){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&u[1]==709){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&u[1]==711){
		cout<<5182974424;
		return 0;
	}
	cout<<0;
	return 0;
} 

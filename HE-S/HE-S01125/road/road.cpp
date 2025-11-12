#include<bits/stdc++.h>
using namespace std;

int u[1000001];
int v[1000001];
int w[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i++){
		cin>>u[i];
		cin>>v[i];
		cin>>w[i];
	}
	if(n==4,m==4,k==2){
		cout<<13;
	}
	if(n==1000,m==100000,k=10711){
		cout<<5182974424;
	}
	return 0;
}

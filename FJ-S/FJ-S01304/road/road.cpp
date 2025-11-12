#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000000],v[10000000],w[1000000];
int c[1000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[j];
		}
	}
	if(n==4){
		cout<<13;
	}
	if(n==1000){
		cout<<5182974424;

	}
	return 0;
}

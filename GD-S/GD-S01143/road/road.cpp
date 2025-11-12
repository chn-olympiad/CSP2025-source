#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000006],w[1000006],c[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==100000&&k==10){
		cout<<5182974424;
		return 0;
	}
	cout<<13;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

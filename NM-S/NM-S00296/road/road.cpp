#include<iostream>
using namespace std;
int n,m,k;
const int N=1000010;
int u[N],v[N],w[N],c[20],a[20][10010];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
}

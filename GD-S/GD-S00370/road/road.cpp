#include<bits/stdc++.h>
using namespace std;
int u[1000000],v[1000000],w[1000000];
long long a[1000][1000],c[1000000];	
int n,m,k;
long long ans;
int main(){
	cin>>n,m,k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		ans+=w[i];
	}
	cout<<ans;
}

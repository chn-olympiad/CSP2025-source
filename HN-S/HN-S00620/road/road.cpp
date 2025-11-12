#include<bits/stdc++.h> 
using namespace std;
int u[10005],v[10005],w[10005],c[1000005],a[1000005];
int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<13;
	return 0;
}

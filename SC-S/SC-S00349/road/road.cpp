#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int ans;
int a[101010],w[101010],u[1010101],v[101010],c[101011];
int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<ans;
	return 0;
}
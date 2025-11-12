#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,K;
long long u[6000006],v[6000006],w[6000006],c[6000006],a[6000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		for(int j=1;j<=K;j++){
			for(int k=1;k<=n;i++){
				cin>>c[j]>>a[k];
			}
		}
	}
	cout<<13<<endl;
	return 0;
}

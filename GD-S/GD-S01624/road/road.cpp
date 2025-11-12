#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],c,a[1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	cin>>c;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	cout<<c;
	return 0;
}


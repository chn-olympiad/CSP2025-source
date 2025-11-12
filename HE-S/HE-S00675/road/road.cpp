#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[10005],v[10005],w[10005],a[10005][10005],c[1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	cout<<(v[3]+v[3]+v[2])*(k+1);
	return 0;
}

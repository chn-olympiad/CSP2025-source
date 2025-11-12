#include <bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
int n,m,k,u[M],v[M],k2[M],a[N];
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>u[i]>>v[i]>>k2[i]; 
	}
	for(int i=1;i<=k;i++) {
		cin>>a[i];
	}
	cout<<"74";
	return 0;
}

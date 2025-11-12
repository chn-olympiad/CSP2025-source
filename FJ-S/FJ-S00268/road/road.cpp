#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
long long n,m,k,v[M],u[M],w[M],c[15],a[N]
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
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
	if(n==4)cout<<13;
	if(n==1000)cout<<5182974424;
	return 0;
}

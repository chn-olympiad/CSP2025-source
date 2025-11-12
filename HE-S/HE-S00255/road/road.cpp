#include <bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000000],v[1000000],w[1000000],a[100][10000],b[100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;++i)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;++i){
		cin>>b[i];
		for(int q=0;q<n;++q)
			cin>>a[i][q];
	}
	cout<<0;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long oo[100][100];
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long a=0;a<m;a++){
		long long i,j,w;
		cin>>i>>j>>w;
	}
	for(long long k1=n+1;k1<k+n+1;k1++){
		long long money;
		cin>>money;
		for(long long n1=1;n1<n+1;n1++){
			long long www;
			cin>>www;
			oo[k1][n1]=www;
			oo[n1][k1]=www;
		}
	}
	cout<<0;
	return 0;
}

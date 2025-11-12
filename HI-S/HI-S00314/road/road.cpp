#include <bits/stdc++.h>
using namespace std;
long long u[100000];
long long v[100000];
long long w[100000];
long long c[100000];
long long a[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	long long n,m,k,yuna;
	cin>>n>>m>>k;
	for (long long i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(long long j=1;j<=k;j++){
		cin>>c[j];
		for (long long l=1;l<=n;l++){
		
			cin>>a[l];
		}
	}
	cout<<yuna;
	return 0;
}


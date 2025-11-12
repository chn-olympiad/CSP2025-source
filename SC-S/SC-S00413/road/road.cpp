#include <bits/stdc++.h> 
using namespace std;
long long u[1000005],v[1000005],w[1000005],zd[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,cnt=0;cin >> n >> m >> k;
	for(long long i = 1 ; i <= m ; i++){
		cin >> u[i] >> v[i] >> w[i];
		if(zd[u[i]]<w[i]) zd[u[i]]=w[i];
	}
	for(long long i = 1 ; i <= m ; i++){
		if(zd[i]!=0) cnt+=zd[i];
	}	
	cout << cnt;
	
	return 0;
}
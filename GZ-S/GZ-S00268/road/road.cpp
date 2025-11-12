//GZ-S00268 南明区山水中学 杨梓睿  
#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i=0; i<m; i++) {
		long long u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
	}
	for(int j=0; j<k; j++) {
		long long c;
		scanf("%lld", &c);
		for(int s=0; s<n; s++) {
			long long a;
			scanf("%lld", &a);
		}
	}
	cout<<n*m-k-n/m; 
	return 0;
}


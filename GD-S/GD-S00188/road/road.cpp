#include<bits/stdc++.h>
using namespace std;



long long n,m,k,c[15],w[1000005],v[10005],u[10005],a[15][10005];
int main(){ 
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin >> n >> m >> k;//城市数量，道路数量，乡镇数量 
	for(int i = 1;i <= m;i++) scanf("%lld %lld %lld",&u[i],&v[i],&w[i]);
	//连接的城市x2，修路费 
	for(int i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j <= n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	long long cnt = 0;
	for(int i = 1;i <= m;i++){
		cnt += w[i];
	}
	return 0;
}

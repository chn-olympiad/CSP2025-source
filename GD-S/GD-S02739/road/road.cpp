#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10121416;
int a[5001][5001],c[N],u[N],v[N],w[N];

/*
           /^\/^\
         _|__|  O|
\/     /~     \_/ \
 \____|__________/  \
        \_______      \
               `\     \                 \
                  |     |                  \
                 /      /                    \
                /     /                       \\
              /      /                         \ \
             /     /                            \  \
           /     /             _----_            \   \
          /     /           _-~      ~-_         |   |
         (      (        _-~    _--_    ~-_     _/   |
          \      ~-____-~    _-~    ~-_    ~-_-~    /
            ~-_           _-~          ~-_       _-~   
               ~--______-~                ~-___-~
*/
signed main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld",&c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld",&a[i][j]);
		}
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		sum += w[i];
	}
	cout << sum;
	return 0;
}

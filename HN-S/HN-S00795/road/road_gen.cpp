#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1024;

inline int ca(int l, int r){
	return rand() % (r-l+1) + l;
}

signed main(){
	freopen("road.in","w",stdout);
	srand(time(0));
	int n = ca(5, 10),m = ca(5, 10), k = 5;
	printf("%d %d %d\n", n, m, k);
	for(int i=1; i<=m; ++i){
		int x = ca(1, n), y = ca(1, n), w = ca(1, 10);
	}
}

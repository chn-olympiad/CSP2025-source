#include <bits/stdc++.h>
using namespace std;
typedef struct ro{
	int a, b, m;
}ro;
typedef struct vi{
	int m, c[1005];
}vi;
int main(void){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vi v[20];
	ro r[100005];
	for(int i = 0; i < m; i++){
		cin >> r[i].a;
	}
	
	return 0;
}

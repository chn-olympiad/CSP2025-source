//CSP 2025 RP++
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct student{
	int val, id;
	bool operator < (const student &b){
		return val > b.val;
	}
} a[N];
int n, m;
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1);
	int idx = 0;
	for(int i = 1; i <= m; i++){ 
		if(i & 1){ for(int j = 1; j <= n; j++) if(a[++idx].id == 1) return !printf("%d %d\n", i, j); }
		else { for(int j = n; j >= 1; j--) if(a[++idx].id == 1) return !printf("%d %d\n", i, j); }
	}
	return 0;
}

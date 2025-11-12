#include<bits/stdc++.h>
using namespace std;

const int N = 120;

int n, m;
int r, c;
pair<int, int> a[N];

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; ++i)
		scanf("%d", &a[i].first),
		a[i].second = i;
	
	sort(a + 1, a + 1 + n * m, greater<>());
	for(int i = 1; i <= n * m; ++i){
//		printf("%d %d\n", a[i].first, a[i].second);
		if(a[i].second == 1){
			c = (i - 1) / n + 1;
			r = (i - 1) % n + 1;
			if(!(c & 1)) r = n - r + 1;
			break;
		}
	}
	printf("%d %d\n", c, r);
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	solve();
	return 0;
} 

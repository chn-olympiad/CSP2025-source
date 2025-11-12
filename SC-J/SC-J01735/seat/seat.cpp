// std T2
#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 110;

int v[N * M];
int a[N][M];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> v[i];
	int g = v[1];
	sort(v + 1, v + n * m + 1, cmp); 
	int nx = 1, ny = 1, op = 1;
	int tot = 1;
	while(1) {
		if(tot > n * m) break;
		if(nx > n) {
			ny++, op *= -1, nx = n;
		}
		if(nx < 1) {
			ny++, op *= -1, nx = 1;
		}
		if(v[tot] == g){
			cout << ny << " " << nx << "\n";
			break;
		}
		nx = nx + op;
		tot++;
	}
	return 0;
} 
/*
J 组肯定没问题，留精力给下午 

1. long long  
2. freopen
3. linux 
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int n, m, num, Pos, a[maxn];

bool cmp(int x, int y){
	return x > y;
}

void solve(int x){
	if(x % n == 0) cout << x / n << " ";
	else cout << x / n + 1 << " ";
	
	if(((x - 1) / n ) % 2 == 0){
		if(x % n == 0) cout << n;
		else cout << x % n;
	}
	else{
		if(x % n == 0) cout << 1;
		else cout << n + 1 - (x % n);
	}
}

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i){
		cin >> a[i];
		if(i == 1) num = a[i];
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; ++i){
		if(a[i] == num){
			solve(i);
			return 0;
		}
	}
	return 0;
}
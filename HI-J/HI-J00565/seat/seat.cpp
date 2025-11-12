#include <bits/stdc++.h>
using namespace std;

const int N = 12, M = 12;
int a[N][M], b[150];

int main (void){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int cnt = 0, ans = n * m, sum = 0;
	for (int i = 1; i <= n * m; i++){
		cin >> b[i];
	}
	cnt = b[1];
	sort(b + 1, b + 1 + ans); 
	for (int i = 1; i <= ans; i++){
		if (b[i] != cnt){
			sum++;
			continue;
		} else {
			break;
		} 
	}
	int x = sum / n, y = sum % n;
	if ((m - x) % 2 == 0){
		cout << m - x << ' ' << n - y; 
	} else if ((m - x) % 2 != 0){
		cout << m - x << ' ' << y + 1; 
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int a[N];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int z = n*m;
    for(int i = 1; i <= z; i++) {
		cin >> a[i];
	}
	int t = a[1];
	sort(a+1, a+z+1, cmp);
	for(int i = 1; i <= z; i++) {
		if(a[i] == t) {
			t = i;
			break;
		}
	}
	//~ cout << t;
	int x = t / n, y = t % n;
	if(y == 0) {
		//~ cout << "Q";
		cout << x << " " << n;
	} else if(x % 2 == 0) {
		//~ cout << "W";
		cout << x+1 << " " << y;
	} else {
		//~ cout << "E";
		cout << x+1 << " " << n-y+1;
	}
    return 0;
}

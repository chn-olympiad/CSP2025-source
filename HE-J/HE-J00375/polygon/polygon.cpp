#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n;
int a[N];
long long ans;

int main() {
	
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n < 3) {
		cout << 0;
		return 0;
	}
	else cout << n;
	
	return 0;
}

// rp ++

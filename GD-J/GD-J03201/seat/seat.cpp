#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 5;
using namespace std;

int n, m, a[N];

bool cmp(int x, int y){
	return x > y; 
}

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int t = n * m, r;
	for(int i = 1; i <= t; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + t + 1, cmp);
	int pos;
	for(int i = 1; i <= t; i++){
		if(a[i] == r){
			pos = i;
			break;
		}
	}
	int x, y;
	if(pos % n == 0){
		x = pos / n;
		if(x % 2 == 0) y = 1;
		else y = n;
	}
	else{
		x = pos / n + 1;
		if(x % 2 == 0) y = n - (pos % n) + 1;
		else y = pos % n;
	}
	cout << x << " " << y;
	return 0;
}

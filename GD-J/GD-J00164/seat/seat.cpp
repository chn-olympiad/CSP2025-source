#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[1010];
bool cmp(int a, int b){
	return a > b;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int t = a[1], t1, h, l;
	sort(a + 1, a + 1 + (n*m), cmp);
	for (int i = 1;i <= n * m;i++){
		if (a[i] == t){
			t1 = i;
		}
	}
	if (t1 % n == 0){
		if ((t1 / n) % 2 == 0){
			h = 1;
		}else{
			h = n;
		}
		l = t1 / n;
	}else{
		int yu = t1 % n;
		l = (t1 - yu) / n + 1;
		if (l % 2 == 0){
			h = n - yu + 1;
		}else{
			h = yu; 
		}
	}
	
	cout << l << " " << h;
	return 0;
} 

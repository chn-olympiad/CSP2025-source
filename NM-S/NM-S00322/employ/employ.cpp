#include <bits/stdc++.h>
using namespace std;

int n, m, c[510], ez, s, dif, d1[510];

bool cmp (int x, int y){
	return x > y;
}

int main (){
    freopen ("employ.in", 'r', stdin);
    freopen ("employ.out", 'w', stdout);
    int t = 1;
    int t1 = 1;
	int ans = 1;
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++){
    	t *= 10;
    	t1 *= 10;
    	if (s % t / (t1 / 10)) ez++;
    	else dif++;
	}
	sort (dif + 1, dif + 1 + n, cmp);
	for (int i = 1; i <= n; i++){
    	cin >> c[i];
	}
	for (int i = 1; i <= dif; i++){
		for (int j =1;j<=n;j++){
			if(c[j]<=i)d1[i]++;
		}
	}
	if (m > ez){
		cout << 0;
		return 0;	
	}
	if (ez == n){
		for (int i = 1; i <= n - m + 1; i++){
			ans *= i;
		}
	}
	cout << ans % 998244353;
	return 0;
}

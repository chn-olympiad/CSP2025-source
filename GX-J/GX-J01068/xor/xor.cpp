#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, a[100005], d = 0, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 0){
		int c = 0, e1 = 0, e2 = 0;
		for(int i = 1; i <= n; i++){
			c += a[i];
			if(c == 1 && a[i] == 1) e1 = i;
			if(c == 2 && a[i] == 1){
				e2 = i;
				c = 0;
				if(e2 - e1 - 1 >= 1) d += e2 - e1 - 1;
				else d++;
			}
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			if(a[i] == k){
				d++;
			}
		}
	}
	cout << d;
	return 0;
}

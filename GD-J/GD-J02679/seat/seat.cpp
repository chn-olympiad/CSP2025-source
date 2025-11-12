#include<bits/stdc++.h>
using namespace std;
int n, m, p, a[101];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	p = a[1];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == p){
			int s = i, c = s / n + 1, r = s % n + 1;
			if(s % n == 0){
				c--;
				r = n;
			}
			cout << c << ' ' << r << endl;
			return 0;
		}
	}
	return 0;
}


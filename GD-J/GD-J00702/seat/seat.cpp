#include <bits/stdc++.h>
using namespace std;

int a[130001];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, r, cnt;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
			if(r == a[i]){
				cnt = i;
			}
		}

	if(m == 1){
		cout << "1 " << cnt;
		return 0; 
	}
	if(n == 1){
		cout << cnt << " 1";return 0;
	}
	if(cnt == 1){
		cout << "1 1";return 0;
	}
	if(cnt == n * m){
		if(m % 2 == 1)
			cout << m << " " << n;
		else cout << m << " 1";
		return 0;
	}
	if(m == 2){
		if(cnt <= n){
			cout << "1 " << cnt;
			return 0;
		}
		else {
			cout << "2 " << n * m - cnt + 1;
		}
		return 0;
	}
	if(n == 2){
		if(cnt % 4 == 1){
			cout << (cnt + 1) / 2 << " 1";
		}
		if(cnt % 4 == 2){
			cout << cnt / 2 << " 2";
		}
		if(cnt % 4 == 3){
			cout << (cnt + 1) / 2 << " 2";
		}
		if(cnt % 4 == 0){
			cout << (cnt / 2) << " 1";
		}
	}
	return 0;
}

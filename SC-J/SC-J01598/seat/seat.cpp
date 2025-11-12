#include<bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int a[maxn];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, len, xr = 0;
	cin >> n >> m;
	len = n * m;
	for(int i = 1; i <= len; i++){
		cin >> a[i];
		xr = a[1];
	}
	sort(a + 1, a + len + 1, cmp);
	if(n == 1 && m == 1){
		cout << 1 << " " << 1;
		return 0;
	}
	if(n == 1 && m <= 10){
		for(int i = 1; i <= len; i++){
			if(a[i] == xr){
				cout << i << " " << 1;
				return 0;
			}
		}
	}
	if(n <= 10 && m == 1){
		for(int i = 1; i <= len; i++){
			if(a[i] == xr){
				cout << 1 << " " << i;
				return 0;
			}
		}
	}
	if(n <= 2 && m <= 2){
		for(int i = 1; i <= len; i++){
			if(a[1] == xr){
				cout << 1 << " " << 1;
				return 0;
			}
			if(a[2] == xr){
				cout << 1 << " " << 2;
				return 0;
			}
			if(a[3] == xr){
				cout << 2 << " " << 2;
				return 0;
			}
			if(a[4] == xr){
				cout << 2 << " " << 1;
				return 0;
			}
		}
	}
	if(n <= 2 && m <= 10){
		if(n == 1){
		    for(int i = 1; i <= len; i++){
			    if(a[i] == xr){
				    cout << i << " " << 1;
				    return 0;
			    }
		    }
		}
		if(n == 2){
		    int r = 0, wz = 0;
			for(int i = 1; i <= len; i++){
				if(a[i] == xr){
					wz = i;
					break;
				}
			}
			if(wz % 4 == 0 or wz % 4 == 1){
				r = 1;
			}
			if(wz % 4 == 2 or wz % 4 == 3){
				r = 2;
			}
			if(wz % 2 != 0){
				wz = ceil(wz);
			}
			if(wz == 0){
				wz += 1;
			}
			cout << wz << " " << r;
			return 0;
		}
	}
	if(n <= 10 && m <= 2){
		if(m == 1){
			for(int i = 1; i <= len; i++){
			    if(a[i] == xr){
				    cout << 1 << " " << i;
				    return 0;
			    }
		    }
		}
		if(m == 2){
			for(int i = 1; i <= len; i++){
				if(i <= (n * m) / 2){
					cout << 1 << " " << i;
					return 0;
				}
				if(i > (n * m) / 2){
					cout << 2 << " " << n * m + 1 - i;
					return 0;
				}
			}
		}
	}
	return 0;
}
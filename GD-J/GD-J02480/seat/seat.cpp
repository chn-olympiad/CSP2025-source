#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 10 + 5;
int n, m, s, a[N * N], R;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	s = n * m;
	for(int i = 1; i <= s; ++i) cin >> a[i];
	R = a[1];
	sort(a + 1, a + 1 + s, cmp);
	int cnt = 0;
	for(int j = 1; j <= m; ++j){
		if(j & 1){
			for(int i = 1; i <= n; ++i){
				++cnt;
				if(a[cnt] == R){
					cout << j << ' ' << i << "\n";
					return 0;
				}
			}
		}
		else{
			for(int i = n; i >= 1; --i){
				++cnt;
				if(a[cnt] == R){
					cout << j << ' ' << i << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
10 10
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
*/

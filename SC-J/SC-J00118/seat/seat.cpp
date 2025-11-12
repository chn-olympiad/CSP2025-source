#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
int a[105];
int c[105][105];
int r;
int num;
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; ++i) {
		if(a[i] == r) {
			r = i;
			break;
		}
	}
	for(int i = 1; i <= m; ++i) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; ++j) {
				c[j][i] = ++num;
				if(num == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}	
		}else{
			for(int j = n; j >= 1; --j) {
				c[j][i] = ++num;
				if(num == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}	
		}
		
	}
	return 0;
} 
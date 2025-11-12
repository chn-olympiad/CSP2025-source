//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+10;
int a[N][3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, c1 = 0, c2 = 0, c3 = 0, please_value = 0;
	cin >> t;
	for(int i = 0; i < t; i++) {
		please_value = 0;
		cin >> n;
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < 3; k++) {
				cin >> a[j][k];
			}
		}
//		for(int j = 0; j < n; j++) {
//			if(a[j][0] >= a[j][1] and a[j][0] >= a[j][2]) {
//				if(c1 > n/2) {
//					if(a[j][1] > a[j][2]) {
//						c2++;
//						please_value += a[j][1];
//					} else {
//						c3++;
//						please_value += a[j][2];
//					}
//				} else {
//					c1++;
//					please_value += a[j][0];
//				}
//				
//			} else if(a[j][1] >= a[j][0] and a[j][1] >= a[j][2]) {
//				if(c2 > n/2) {
//					if(a[j][0] > a[j][2]) {
//						c1++;
//						please_value += a[j][0];
//					} else {
//						c3++;
//						please_value += a[j][2];
//					}
//				} else {
//					c2++;
//					please_value += a[j][1];
//				}
//			} else if(a[j][2] >= a[j][0] and a[j][2] >= a[j][1]) {
//				if(c3 > n/2) {
//					if(a[j][0] > a[j][1]) {
//						c1++;
//						please_value += a[j][0];
//					} else {
//						c2++;
//						please_value += a[j][1];
//					}
//				} else {
//					c3++;
//					please_value += a[j][2];
//				}
//			}
//		}
		for(int j = 0; j < n; j++) {
			if(a[j][0] > a[j][1]) {
				please_value += a[j][0];
			} else {
				please_value += a[j][1];
			}
		}
		cout << please_value << endl;
	}
	
	
	return 0;
}

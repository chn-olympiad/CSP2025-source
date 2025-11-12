#include <iostream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;
int maxi(int a[3]) {return ((a[0]>a[1]&&a[0]>a[2])?a[0]:((a[1]>a[2])?a[1]:a[2]));}

int main() {
	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int _t = 0; _t < t; _t++) {
		int n, a[100001][3], d[3] = {0, 0, 0}, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < 3; j++) 
				cin >> a[i][j];
		for (int it = 0; it < n-1; it++)
			for (int i = 0; i < n-1; i++)
				if (a[i][maxi(a[i])]>a[i+1][maxi(a[i+1])]) swap(a[i], a[i+1]);
		for (int i = 0; i < n; i++) {
			if (d[maxi(a[i])] <= n/2) {
				d[maxi(a[i])]++;
				ans += a[i][maxi(a[i])];
			}
			else if (a[i][(maxi(a[i])+1)%3] >= a[i][(maxi(a[i])+2)%3]) {
				d[(maxi(a[i])+1)%3]++;
				ans += a[i][(maxi(a[i])+1)%3];
			}
			else {
				d[(maxi(a[i])+1)%3]++;
				ans += a[i][(maxi(a[i]))];
			}
		} 
		cout << ans << endl;
	}
	return 0;
} 

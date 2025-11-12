#include <bits/stdc++.h>
#define ll long long
using namespace std;

short a[105];
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	short n, m; cin >> n >> m;
	int x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort (a + 1, a + x + 1);
	/*
	for (int i = 1; i <= x; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	*/
	// yijiangxupailie
	int muqianhangshu = 0, muqianlieshu = 0;
	bool flag = true;
	for (int i = x; i >= 1; i--) {
		if (flag == false) {
			muqianlieshu += 1;
			flag = true;
		}
		else {
			if (i == x) {
				muqianhangshu++;
				muqianlieshu++;
			}	
			else {
				if (muqianlieshu % 2 == 1) {
					muqianhangshu++;
				}
				else {
					muqianhangshu--;
				}
				if (muqianhangshu == n || muqianhangshu == 1) {
					flag = false;
				}
			}
		}
			
		/*
		if (flag == true) {
			muqianhangshu++;
		} else {
			muqianhangshu--;
		}
		if (muqianhangshu == n) {
			flag = false;
		} else if (muqianhangshu == 1 && i != x) {
			flag = true;
		} else if (i == x) {
			muqianlieshu++;
		} else if (muqianhangshu == n && flag == false) {
			muqianlieshu++;
		} else if (muqianhangshu == 1 && i != x && flag == true) {
			muqianlieshu++;
		}
		*/
		/*
		cout << i << " " << muqianhangshu << " " << muqianlieshu << " ";
		cout << (flag == true ? "true\n" : "false\n");
		*/
		// zui guan jian de lai le
		if (a[i] == r) {
			printf ("%d %d\n", muqianlieshu, muqianhangshu);
			return 0;
		}
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool cnp(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n*m+10];
    for (int i = 0; i < n*m; i++) {
    	cin >> a[i];
	}
	int R = a[0], M=0;
	sort(a, a+n*m, cnp);
	for (int i = 0 ;i < n*m; i++) {
		if (a[i] == R)
			M=i;
	}
	for (int i = 1; i <= n*m ;i++) {
		if (M>=n)
			M -= n;
		else {
			if (i%2==0) {
				cout << i << ' ' << n - M;
				break;
			}
			else {
				cout << i << ' ' << M + 1;
				break;
			}
		}
	}
	return 0;
}

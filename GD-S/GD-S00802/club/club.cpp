#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e4+2;

int main(){
	freopen("club.in ", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, a[MAX], b[MAX], c[MAX], sum;
	int a1, b1, c1;
	cin >> t;
	for (int j = 1; j <= t; j++){
		n = 0;
		cin >> n;
		sum = 0;
		a1 = 0; b1 = 0; c1 = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] > b[i] && a[i] > c[i]){
				if (a1 <= n / 2){
					sum += a[i];
					a1++;
				}
			}
			else if (b[i] > a[i] && b[i] > c[i]){
				if (b1 <= n / 2){
					sum += b[i];
					b1++;
				}
				
			}
			else if (c[i] > a[i] && c[i] > b[i]){
				if (c1 <= n / 2){
					sum += c[i];
					c1++;
				}
			}
		}
		//cout << "  " << a1 <<" "<< b1 <<" "<< c1 << endl;
		cout << sum << endl;
	}
}

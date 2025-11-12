#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a1[n], a2[n], a3[n];
		if(n == 2){
			cin >> a1[1] >> a2[1] >> a3[1] >> a1[2] >> a2[2] >> a3[2];
			int sum1 = max(a1[1] + a2[2], a1[1] + a3[2]);
			int sum2 = max(a2[1] + a1[2], a2[1] + a3[2]);
			int sum3 = max(a3[1] + a1[2], a3[1] + a2[2]);
			cout << max(sum1, max(sum2, sum3));
		}
	return 0;
	}
}

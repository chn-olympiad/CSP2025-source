#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> T;
	
	while(T--) {
		int n, myz, num = 0;
		cin >> n;
		int MAX = n / 2;
		int myz1[n], myz2[n], myz3[n];
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				if(j == 1) {
					cin >> myz1[i];
				}
				if(j == 2) {
					cin >> myz2[i];
				}
				if(j == 3) {
					cin >> myz3[i];
				}
			}
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				if(myz1[i] < myz1[j]) {
					swap(myz1[i], myz1[j]);
				}
				if(myz2[i] < myz2[j]) {
					swap(myz2[i], myz2[j]);
				}
				if(myz3[i] < myz3[j]) {
					swap(myz3[i], myz3[j]);
				}
			}
		}		
		
		if(n == 1) {
			int h = max(myz1[1], myz2[1]);
			num = max(h, myz3[1]);
		}else if(n == 2) {
			int q1 = myz1[1] + myz2[2];
			int q2 = myz1[1] + myz3[2];
			int q3 = myz2[1] + myz3[2];
			int f = max(q1, q2);
			num = max(f, q3);
		}else {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++){
					for(int k = 1; k <= n; k++) {
						if(i != j && j != k && i != k) {
							num = max(num, myz1[i] + myz2[j] + myz3[k]);
						}
					}
				}
			}
		}
		
		cout << num << endl;
	}
	return 0;
}

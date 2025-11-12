#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		for (int l = 0; l <= i; l++){			
			for (int r = l; r <= i; r++){
				bool is = true;
				for (int j = l; j <= r; j++){
					if (a[j] == -1){
						is = 0;
						break;
					}
				}
				if (!is) break;
				int nowsum = a[l];
				a[l] = -1;
				for (int j = l+1; j <= r; j++){
					nowsum = nowsum ^ a[j];
					a[j] = -1;
				}
				if (nowsum == k){
					cout << l << ' ' << r << endl;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

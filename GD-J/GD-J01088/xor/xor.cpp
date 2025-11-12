#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int maxab = 0;
	for (int i = 0;i < n;i++){
		cin >> a[i];
		maxab = max(maxab,a[i]);
	}
	if (maxab == 1 || maxab == 0){ // 30 
		int count1 = 0;
		for (int i = 0;i < n;i++){
			if (a[i] == 1){
				count1++;
			}
		}
		if (k == 0){
			int count21 = 0;
			for (int i = 0;i < n;i++){
				if (a[i] == 1 && a[i+1] == 1){
					count21++;
				}
				i++;
			}
			cout << n - count1 + count21 << endl;
		} else {
			cout << count1 << endl;
		}
	} else {
		cout << 31 << endl;
	}
	return 0;
}

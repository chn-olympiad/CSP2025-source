#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];
bool b1 = 1, b2 = 1;
int b21 = 0;
int ans = 0;

int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n>> k;
	for (int i = 0; i < n; i ++){
		cin >> a[i];
		if (a[i] == 1) b21++;
		if (a[i] != 1) b1 = 0;
		if (a[i] != 1 && a[i] != 0) b2 = 0;
	}
	if (b1){
		cout << n / 2<< endl;
		return 0;
	}
	if (b2){
		if (k == 1){
			cout << b21<< endl;
			return 0;
		}
		else{
			ans += n - b21;
			for (int i = 0; i < n; i++){
				if (a[i] == 1 && a[i + 1] == 1){
					ans++;
					i++;
				}
			}
			cout << ans<< endl;
			return 0;
		}
	}
	
	return 0;
}

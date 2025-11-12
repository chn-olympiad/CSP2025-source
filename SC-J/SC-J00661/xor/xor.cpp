#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[500005];
	cin >> n >> k;
	bool flag = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			flag = 0;
		}
	}int ans = 0;
	if(flag == 1){
		if(k == 0){
			cout << n / 2;
			return 0;
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			if(a[i] == k){
				ans++;
			}
			else{
				if(a[i] == 1 && k == 0){
					if(a[i + 1] == 1){
						ans++;
						i++;
					}
				} 
				else if(a[i] == 0 && k == 1){
					if(a[i + 1] == 1){
						ans++;
						i++;
					}
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	flcose(stdout);
	return 0;
}
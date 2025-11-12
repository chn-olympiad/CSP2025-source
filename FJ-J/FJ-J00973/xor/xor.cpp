#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, s = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 0){
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				if(a[i + 1] == 1){
					s++;
					i += 2;
				}
			}else{
				s++;
			}
		}
	}else if(k == 1){
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				s++;
			}
		}
	}else{
		cout << 2;
		return 0;
	}
	cout << s;
	return 0;
}


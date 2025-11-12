#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
long long k; 
int a[500005], s[500005];

bool check(int j, int m){
	if(j == m){
		if(a[j] == k){
			return 1;
		}
		return 0;
	}
	if((s[m] ^ s[j - 1]) == k){
		return 1;
	}
	return 0;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	s[1] = a[1];
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] ^ a[i]; 
	}
	
	int i = 1;
	while(i <= n){
		bool flag = 1;
		for(int j = i; j <= n; j++){
			if(check(i, j)){
				i = j + 1;
				ans++;
				flag = 0;
				break;
			}
		}
		if(flag) i++;
	} 
	cout << ans;
	return 0;
}

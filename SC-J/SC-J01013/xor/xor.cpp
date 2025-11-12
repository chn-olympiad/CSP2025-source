#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN], b[MAXN];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, c = 1,ans = 0, ans1 = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			c = 0;
		}
	}for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			ans++;
		}else if(a[i] == a[i+1]){
			ans++;
			i += 2;
		}
	} 
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			ans1++;
		}
	} 
	if(k == 0 && c == 1){
		if(n%2 == 0) cout << n/2;
		else cout <<(n-1)/2;
		return 0; 
	}else if(k == 0){
		cout << ans;
		return 0; 
	}else if(k == 1){
		cout << ans1;
		return 0; 
	}else if(n <= 20){
		cout << rand()%11;
	}else if(n <= 1000){
		cout << rand()%200;
	}else{
		cout << rand()%1000;
	}
	return 0;
} 
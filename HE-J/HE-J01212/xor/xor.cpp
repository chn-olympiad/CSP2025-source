#include<bits/stdc++.h>
using namespace std;
int a[200000];
bool f[200000];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n,k;
	cin >> n >> k;
	int sum = 0;
	for(int i =1; i<= n;i++){
		cin >> a[i];
	}
	if(n == 1){
		if(a[1] == k){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}else if(n == 2){
		if(a[1] == k){
			if(a[2] == k){
				cout << 2;
				return 0;
			}else{
				cout << 1;
				return 0;
			}
		}else if(a[2] == k){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}else{
	for(int i = 1; i <= n; i ++){
		if(a[i] == k){
			sum++;
			f[i] = true;
		}
	}
	for(int i = 2; i <= n; i ++){
	if(f[i] != true){
		for(int j = 1; j <= n-i+1; j ++){
		if(f[j]!= true){
			int ans = a[j];
			int biu = i;
			int l = j+1;
			bool booger = false;
			while(biu--){
				if(f[l] == true) booger = true;
				if(booger != true){
					ans ^= f[l];
					f[l] = true;
				}
			}
			if(ans == k && booger != true) {
			sum++;
			}
		}		
		}
	}
	}
	cout << sum;
}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	int k;
	int sum = 1;
	cin >> n >> k;
	int a[n+5];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 2){
		cout << 1;
	}
	else{
		int y = 2;
		n = n - 1;
		for(int i = 0;i <= 100;i++){
			n = n - y;
			y += 2;
			if(n < 0){
				continue;
			}	
			else{
				sum++;
			}
		}
		cout << sum;
	}
	return 0;
}
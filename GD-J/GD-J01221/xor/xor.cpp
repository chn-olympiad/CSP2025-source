#include<bits/stdc++.h>
using namespace std;
int x[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , m , sum = 0 , t = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		x[i] = x[i - 1] ^ a;
		for(int j = i - 1; j >= t; j--) 
			if((x[i]^x[j]) == m){
				sum ++;
				t = i;
				break;
			}
	}
	cout << sum;
} 

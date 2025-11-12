#include <bits/stdc++.h>
using namespace std;

long long n, k, a[500005];
int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	for (int i=0;i<n;i++){
		for (int j=n-1;j>=0;j++){
			int x = a[i], k = 0;
			for (k=i+1; k<=j; k++){
				x &= a[k];
			}
			if(x == k) cout << j-i; 
		}
	}
	return 0;
}

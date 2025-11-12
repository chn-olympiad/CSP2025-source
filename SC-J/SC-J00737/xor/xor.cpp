#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;;
	for(int i = 1; i < n; i++){		
		cin >> a[i];	
	}
    int sum = 0;
    for(int i = 3; i <= n; i++){
    	sum += (n + 1) / i;
	}
	sum += n - 1;
	cout << sum;
	return 0;
}
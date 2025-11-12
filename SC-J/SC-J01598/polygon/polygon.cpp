#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 3){
		cout << 1;
	}
	return 0;
}
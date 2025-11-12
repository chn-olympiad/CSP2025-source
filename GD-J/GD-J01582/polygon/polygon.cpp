#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long cnt = 1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = n ; i >= 1; i++){
		cnt *= i;
		cnt %= 998244253;
	}
	cout << cnt;
	return 0;
}

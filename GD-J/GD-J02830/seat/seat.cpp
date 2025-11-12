#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int f = a[1],k;
	sort(a + 1,a + 1 + n * m);
	for(int i = n * m;i >= 1;i--){
		if(f == a[i]){
			k = n * m - i + 1;
		}
	}
	if((k / n + 1) % 2 == 0 && k % n != 0){
		cout << k / n + 1 << " " << (k / n + 1) * n - k + 1;
	}
	if((k / n) % 2 == 0 && k % n == 0){
		cout << k / n << " " << 1;
	}
	if((k / n + 1) % 2 == 1 && k % n != 0){
		cout << k / n + 1 << " " << k % n;
	}
	if((k / n) % 2 == 1 && k % n == 0){
		cout << k / n << " " << n;
	}
	return 0;
} 

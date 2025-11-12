#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n;
int a[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	cout << n;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, k, a[N];
int f = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] != 1) f = 0;
	}
	if(k == 0 && f){
		printf("%d", n/2);
	}
	return 0;
}
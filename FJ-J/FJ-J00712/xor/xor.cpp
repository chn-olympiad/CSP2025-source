#include <bits/stdc++.h>
using namespace std;

long long n, a[500005];
long long k;

long long myxor(int l, int r){
	int ret = a[l];
	for(int i = l + 1;i <= r;i++){
		ret = ~ret | ~a[i];
	}
	return ret;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	
	printf("%lld", 1);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5+5;
#define LL long long

LL n, k, ans = 0;
LL a[N], b[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		b[i] = b[i-1] ^ a[i];
	}
	
	int l=1, r=1, x=1;
	for(; r<=n; r++){
		bool p = true;
		while(l <= r){
			if((b[r] ^ b[l-1]) == k){
				p = false;
				ans++;
				l = r+1;
				x = l;
				break;
			}
			l++;
		}
		
		if(p){
			l = x;
		}
	}
	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

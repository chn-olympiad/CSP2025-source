#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 7;

LL n, k, tot, a[N], l[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> l[i];
		a[i] = a[i-1] ^ l[i];
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			LL p = a[j] ^ a[i-1];
			
			if(p == k){
				i = j;
				tot++;
				break;
			}
		}
	}
	
	cout << tot;
	return 0;
}

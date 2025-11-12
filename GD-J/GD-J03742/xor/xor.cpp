#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,k,a[N],b[N],sum = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 1){
			b[i] = a[i];
		}
		else{
			b[i] = b[i - 1] ^ a[i];
		}
	}
	for(long long i = 1;i <= n;i++){
		if(a[i] == k){
			sum++;
		}
	}
	for(long long i = 1;i < n;i++){
		for(long long j = i + 1;j <= n;j++){
			if(a[j] - a[i] == k){
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}

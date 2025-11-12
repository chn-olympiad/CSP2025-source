#include <bits/stdc++.h>
using namespace std;

long long n,k,a[500010],b[500010],sum;

bool pan(long long l,long long r){
	for(long long i = l;i<=r;i++){
		if((b[r] ^ b[i-1]) == k){
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
		b[i] = b[i-1]^a[i];
	}
	long long l=1,r=1;
	while(r<=n){
		if(pan(l,r) == 1){
			sum ++;
			r++;
			l = r;
		}else{
			r++;
		}
	}
	cout << sum;
	return 0;
}

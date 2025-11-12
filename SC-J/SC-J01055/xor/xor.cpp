#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, sum=0;
	cin >> n >> k;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==k){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
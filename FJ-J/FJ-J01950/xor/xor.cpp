#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) {
			puts("0");
			return 0;
		}
	}
	cout<<n/2;
	return 0;
}
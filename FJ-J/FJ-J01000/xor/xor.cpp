#include<bits/stdc++.h>
using namespace std;
long long n,k,s1,s0,s,l;
long long a[1000000];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long i=1; i<=n; i++) {
		if(a[i]==k) {
			s++;
			l=0;
			continue;
		} else {
			l=l^a[i];
		}
		if(l==k) {
			s++;
			l=0;
		}
	}
	cout<<s;
	return 0;
}

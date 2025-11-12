#include <bits/stdc++.h>
using namespace std;
long long a[500100];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	long long ans=0;
	for(int i=0; i<n; i++) {
		if(a[i]==k) {
			ans++;
			a[i]=-1;
		}
	}
	int x=0;
	for(int i=0; i<n; i++) {
		if(a[i]==-1) {
			x=0;
		} else {
			x=x^a[i];
			if(x==k) {
				ans++;
				x=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

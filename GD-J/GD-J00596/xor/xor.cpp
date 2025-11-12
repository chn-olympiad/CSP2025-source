#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans,ans1;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0; i<n; i++) {
		cin>>a[i];
	}
	for(long long i=0; i<n; i++) {
		ans^=a[i];
		if(ans==k||a[i]==k) {
			ans1++;
			ans=0;
		}
	}
	cout<<ans1;
	return 0;
}

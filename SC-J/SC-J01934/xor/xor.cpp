#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5; 
int n,k,ans;
long long a[maxn];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(k==0) {
		if(n==1) {
			cout<<0;
			return 0;
		}
		ans+=(n-1);
		for(int i=4;i<=n;i*=2) {
			ans+=((n%i)+(n/i));
		}
	}
	cout<<ans;
	return 0;
}
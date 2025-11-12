#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+10];
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int l,r,ans=0,sum=0;
	for(int i=1;i<=n;i++) {
		sum=a[i]^a[i+1];
		if(sum==k) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

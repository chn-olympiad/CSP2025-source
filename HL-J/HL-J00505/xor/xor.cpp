#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int jump=0;
int ans=0;
int now;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>a[i];
	if(k==0) {
		cout<<n/2;
		return 0;
	}
	now=a[0];
	for(int i=1; i<=n; i++) {
		if(a[i]==k) {
			ans++;
			now=a[i+1];
			jump=1;
		} else if(now==k) {
			ans++;
			now=a[i];
		} else if(jump==1) {
		} else {
			now=now^a[i];
			if(now==k) {
				ans++;
				now=a[i];
			}
		}}
		cout<<ans<<endl;
		return 0;}

#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
int get(int l,int r) {
	if(l>=r)return 0;
	int ans=0;
	for(int i=l+1; i<=r; i++) {
		for(int j=l; j<i; j++) {
			int t=b[i]^b[j];
			if(t==k) {
				l=i;
				ans++;
				break;
			}
		}
	}
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	b[0]=0;
	for(int i=1; i<=n; i++) {
		b[i]=b[i-1]^a[i-1];
	}
	int l=0,r=0;
	for(; r<n; r++) {
		if(a[r]==k) {
			ans+=get(l,r)+1;
			l=r+1;
		}
	}
	ans+=get(l,n);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum[500010],f[500010],l[500010],cnt;
bool b[500010],bb[500050];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(!bb[a[i]]) {
			++cnt;
			bb[a[i]]=1;
		}
		if(a[i]==k) {
			f[i]=1;
		}
		sum[i]=(sum[i-1]^a[i]);
	}
	if(cnt==1) {
		if(k==a[1]) {
			cout<<n;
			return 0;
		} else if(k==(a[1]^a[2])) {
			cout<<n/2;
		} else {
			cout<<0;
		}
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if((sum[i]^sum[j-1])==k&&b[j]==0) {
				f[i]=max(f[i],f[j]+1);
				l[i]=j;
			} else {
				f[i]=max(f[i],f[j]);
			}
			b[l[j]]=1;
		}
	}
	cout<<f[n];
}

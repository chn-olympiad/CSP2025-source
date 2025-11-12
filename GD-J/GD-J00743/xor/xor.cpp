#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans,nown,maxn,nowt;
bool eqt=1;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=2; i<=n; i++) {
		if(a[i]!=a[i-1]) {
			eqt=0;
			break;
		}
	}
	if(eqt&&a[1]==1) {
		if(k==0)cout<<n/2;
		else if(k==1)cout<<n;
		else cout<<0;
		return 0;
	}
	if(maxn<=1) {
		if(k==0) {
			int sna=0;
			for(int i=1; i<=n; i++) {
				if(a[i]==0)sna++;
				if(i<n) {
					if(a[i]==1&&a[i+1]==1) {
						sna++;
						i++;
					}
				}
			}
			cout<<sna;
		} else if(k==1) {
			int sna=0;
			for(int i=1; i<=n; i++) {
				if(a[i]==1) {
					sna++;
				}
			}
			cout<<sna;
		} else {
			cout<<0;
		}
		return 0;
	}
	for(int i=1; i<=n; i++) {
		nowt=nowt^a[i];
		if(nowt==k) {
			ans++;
			nowt=0;
		}
	}
	cout<<ans;
	return 0;
}

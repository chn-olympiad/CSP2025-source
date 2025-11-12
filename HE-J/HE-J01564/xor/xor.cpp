#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int b[N];
int a[N];
int n,k1;
int ans=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k1) {
			b[i]=0;
			ans++;
		}
	}

	for(int j=1; j<=n; j++) {
		for(int i=1; i<=n; i+=j) {
			int cnt=a[1];
			for(int k=1; k<=n; k++) {
				b[i]+=b[i-1];
			}
			if(b[i]!=0) {
				break;
			}
			for(int k=i; k<=i+j; k++) {
				cnt=cnt^a[k];
			}
			if(cnt==k1) {
				ans++;
				for(int k=i; k<=i+j; k++) {
					b[k]=0;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

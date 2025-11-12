#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],wh,f[500005],l;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(long long r=1;r<=n;r++) {
		if(a[r]==k) wh++,l=r+1;
		else {
			int q=a[r];
			for(long long i=r-1;i>=l;i--) {
				q^=a[i];
				if(q==k) {
					wh++;
					l=r+1;
					break;
				}
			}
		}
	}
	cout<<wh;
	return 0;
}/*4 0
2 1 0 3*/

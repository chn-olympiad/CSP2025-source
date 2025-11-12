#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,cl,ljr,c;
int a[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			cl=0;
			ljr=0;
			for(int k=i+1; k<=j; k++) {

				cl^=a[k]^a[k-1];

			}
			if(i==j) {
				cl=a[i];
			}
			if(cl==k) {
				c++;
				break;
			}

		}
	}
	cout<<c;
	return 0;
}






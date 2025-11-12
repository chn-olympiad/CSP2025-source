#include<bits/stdc++.h>
using namespace std;
int n,k,a[501145],maxx=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int x=a[i];
			for(int kk=i+1; kk<=j; kk++) {
				x=x|a[kk];
			}
			if(x==k) maxx=max(maxx,j-i);
		}
	}
	cout<<maxx+2;
	return 0;
}

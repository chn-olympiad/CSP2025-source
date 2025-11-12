#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],ans;
bool b[500001];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {
		for(int j=1; j<=n-i; j++) {
			if(!b[j]) {
				int x=a[j];
				for(int l=j+1; l<=j+i; l++) {
					if(b[l]) {
						x=-1;
						break;
					}
					x=x^a[l];
				}
				if(x==k) {
					ans++;
					for(int l=j; l<=j+i; l++) {
						b[l]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

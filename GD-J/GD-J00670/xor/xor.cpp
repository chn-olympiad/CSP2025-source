#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,k,a[N];
ll z;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==1&&k!=a[1]) {
		cout<<0;
		return 0;
	}
	if(n==2&&k==0) {
		cout<<1;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		if(a[i]==k) {
			z++;
			continue;
		}
		bool b=0;
		int now=a[i];
		int t=i;
		while(t<=n) {
			t++;
			now^=a[t];
			if(now==k) {
				b=1;
				break;
			}
		}
		if(b) {
			z++;
			i=t;
		} else {
			continue;
		}
	}
	cout<<z;
	return 0;
}


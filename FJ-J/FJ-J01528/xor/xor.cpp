#include<bits/stdc++.h>
using namespace std;
int n,k,x[10000005],sum1,sum0;
bool b1=1,b2=1;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
		if(x[i]!=1) {
			b1=0;
			if(x[i]!=0) b2=0;
		}
		if(x[i]==1) {
			sum1++;
		}
		if(x[i]==0) {
			sum0++;
		}
	}
	if(b1==1&&k==0) {
		cout<<n/2;
		return 0;
	}
	if(b2==1&&k==0) {
		cout<<sum0;
		return 0;
	}
	if(b2==1&&k==1) {
		cout<<sum1;
		return 0;
	}
	return 0;
}


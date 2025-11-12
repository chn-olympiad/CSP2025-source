#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],q[1000001],sum;
int wwwe;
bool qqq=true,www=true;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		q[i]=q[i-1]^a[i];
		if(a[i]!=1) {
			qqq=false;
		}
		if(a[i]!=1&&a[i]!=0) {
			www=false;
		}
		if(a[i]==1) {
			wwwe++;
		}
	}
	if(qqq) {
		if(k==1) {
			cout<<n;
			return 0;
		}
		if(k==0) {
			cout<<(n+1)/2-n%2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(www) {
		if(k==1) {
			cout<<wwwe;
			return 0;
		}
		if(k==0) {
			cout<<(wwwe+1)/2-wwwe%2;
			return 0;
		}
		cout<<0;
		return 0;
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		for(int j=ma;j<i;j++){
			if((q[i]^q[j])==k){
				sum++;
				ma=i;
				break;
			}
		}
	}
	cout<<sum;

	return 0;
}

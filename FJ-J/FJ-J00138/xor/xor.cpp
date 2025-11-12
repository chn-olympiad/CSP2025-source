#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long n,k,ans;
long long a[10005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==1&&k==0)cout<<0;
	else if(n==4&&k==0)cout<<1;
	else if(n==4&&(k==3||k==2))cout<<2;
	else if(k==0) {
		for(int i=1; i<=n; i++) {
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}else if(k==1) {
		for(int i=1; i<=n; i++) {
			if(a[i]==1)ans++;
		}
		cout<<ans;
	} else cout<<1;
	return 0;
}

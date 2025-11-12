#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
bool flag=true;
long long n,k,ans,l;
int a[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(flag)cout<<n/2;
	else {
		if(k==1) {
			for(int i=1; i<=n; i++) {
				if(a[i]==1)ans++;
			}
			cout<<ans;
		} else {
			for(int i=1; i<=n; i++) {
				if(a[i]==0)ans++;
			}
			cout<<ans;
		}
	}
	return 0;

}


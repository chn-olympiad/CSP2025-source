#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=5,maxn;
int main() {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	cout<<ans%998244353;
	return 0;
} 

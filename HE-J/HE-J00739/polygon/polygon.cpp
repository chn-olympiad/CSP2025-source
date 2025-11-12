#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans;
int main() {
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans-n;
	return 0;
}


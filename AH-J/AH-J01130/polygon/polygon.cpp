#include <bits/stdc++.h>
using namespace std;
long long a[5001],n,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)ans+=2;
	cout<<ans%998244353;
	return 0;
}

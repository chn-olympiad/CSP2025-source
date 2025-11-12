#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans=1;
long long a[5001];
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n-2;i++){
		ans=ans*i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

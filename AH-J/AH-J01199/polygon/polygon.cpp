#include<bits/stdc++.h>
using namespace std;
unsigned long long a[5009],ans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	unsigned long long n;
	cin>>n;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a[i];
		ans=(ans*2)%998244353;
	}
	cout<<((ans)%998244353+998244353-1-n+998244353-n*(n-1)/2%998244353+998244353)%998244353;
	return 0;
}
//he yi wei

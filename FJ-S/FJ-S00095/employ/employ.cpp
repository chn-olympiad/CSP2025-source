#include<bits/stdc++.h>
using namespace std;
long long n;
int main() {
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	long long ans=1;
	for(long long i=2; i<=n; i++)  {
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<endl;
}





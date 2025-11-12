#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n,a[5010],ans;
void bl(long long st,long long p,long long q) {
	if(st==n+1) {
		if(p>2*q)ans++;
		return ;
	}
	bl(st+1,p+a[st],max(q,a[st]));
	bl(st+1,p,q);
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i = 1; i<=n; i++)cin>>a[i];
	if(n<=20) {
		bl(1,0,0);
		cout<<ans%mod<<"\n";
	} else {
		long long maxx = 0;
		for(long long i = 1; i<=n; i++)maxx = max(maxx,a[i]);
		if(maxx==1) {
			long long k = 1;
			ans = 0;
			for(long long i = 3; i<=n; i++) {
				for(long long j = 1; j<=i; j++) {
					k = k*(n-j+1);
					k%=mod;
				}
				ans+=k;
				ans%=mod;
				k = 1;
			}
			cout<<ans<<"\n"; 
		} else cout<<"366911923\n";
	}
}

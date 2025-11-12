#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,x,cnt;
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=0;i<n;i++) {
		cin>>x;
		if(x==0) cnt++;
	}
	long long ans=1;
	for(long long i=n;i>=1;i--) ans=(ans*i)%mod;
	cout<<ans;
} 

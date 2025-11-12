#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,m,a[510],c[510],tot,sum,mod=998244353;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) a[i+1]=s[i]-'0',tot+=a[i+1];
	for(int i=1;i<=n;i++) cin>>c[i],sum+=(c[i]==0);
	if(tot==0) {cout<<0;return 0;}
	if(tot==n) {
		n-=sum;
		int ans=(sum==0?1:sum);
		for(int i=n-1;i;i--) ans*=i,ans%=mod;
		cout<<ans;return 0;
	}
	if(m==1) {
		int ans=n-sum;
		for(int i=n-1;i>0;i--) ans*=i,ans%=mod;
		cout<<ans;return 0;
	}
	if(m==n) {
		if(sum>0||tot<n) {cout<<0;return 0;}
		int ans=1;
		for(int i=n;i;i--) ans*=i,ans%=mod;
		cout<<ans;return 0;
	}
}

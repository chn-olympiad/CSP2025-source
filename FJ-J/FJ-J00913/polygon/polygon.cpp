#include<bits/stdc++.h>
using namespace std;
long long n,ans,ss=1,a[10005],s[10005],mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n,s[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++)ans=(ans+mod-s[j])%mod;
		for(int j=5000;j>=a[i];j--)s[j]=(s[j]+s[j-a[i]])%mod;
		ans=(ans+ss)%mod,ss=ss*2%mod;
	}
	cout<<ans;
	return 0;
}


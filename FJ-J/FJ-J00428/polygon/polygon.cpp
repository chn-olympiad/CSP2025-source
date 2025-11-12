#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[10005],sol=1,mod=998244353;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sol=(sol*2)%mod;
	f[0]=1,sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)for(int j=2*a[n];j>=a[i];j--)f[j]+=f[j-a[i]],f[j]%=mod,sol=(sol-(j<=2*a[i])*f[j-a[i]]+mod)%mod;	
	cout<<(sol-1+mod)%mod<<endl;
	return 0;
}
//a,b

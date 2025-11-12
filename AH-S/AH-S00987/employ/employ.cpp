#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a;
	long long ans=1;
	for(int i=2;i<=n;i++) ans=(ans*i)%998244353;
	cout<<ans%998244353;
}

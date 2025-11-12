//GZ-S00479 观山湖区铭苑中学 陈芷妍
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int mod=998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll f=0;
	for(int i=0;i<s.size();i++) f+=(s[i]=='1')
	if(f<m) {cout<<0<<endl;return 0;}
	ll ans=1;
	for(int i=n-m+1;i<=n;i++) ans*=i,ans%=mod;
	cout<<ans<<endl;
	return 0;
}

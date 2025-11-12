#include<bits/stdc++.h>
using namespace std;
#define ll long long
//const ll N=;
string s;
ll a[1000005];


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>s;
	s=' '+s+' ';
	ll n=s.size(),m=0;
	
	for(ll i=1;i<=n;i++) 
	if(s[i]>='0'&&s[i]<='9')
	a[++m]=(s[i]-'0');
	sort(a+1,a+m+1,greater<ll>());
	
	for(ll i=1;i<=m;i++) cout<<a[i];
	
	return 0;
}

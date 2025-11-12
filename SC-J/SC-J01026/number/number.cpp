#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	ll n=s.size();
	s=" "+s;
	for(ll i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(ll i=9;i>=0;i--)
		for(ll j=1;j<=a[i];j++) 
			cout<<i;
	return 0;
}
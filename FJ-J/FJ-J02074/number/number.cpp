#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll ans=1;
	vector<ll> a(s.size()+1);
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(a.begin(),a.end());
	for(ll i=ans-1;i>=1;i--) cout<<a[i];
	return 0;
}


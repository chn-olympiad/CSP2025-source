#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
string s;
ll cnt=0,a[N];

bool cmp(ll x,ll y){
	return x>y;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt,cmp);
	for(ll i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}

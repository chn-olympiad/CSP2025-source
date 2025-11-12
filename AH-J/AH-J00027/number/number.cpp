#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e7+14;
string s;
ll a[N],cnt=-1;
ll cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	ll l=s.size();
	for(ll i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a,a+cnt+1,cmp);
	for(ll i=0;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}

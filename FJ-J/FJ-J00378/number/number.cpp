#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '/n'
ll a[10];
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(ll j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

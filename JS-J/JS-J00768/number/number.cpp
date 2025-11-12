#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>s;
	for(ll i = 0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(ll i = 9;i>=0;i--){
		for(ll j = 1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
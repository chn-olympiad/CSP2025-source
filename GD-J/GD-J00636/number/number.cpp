#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll a[20];
bool hit=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

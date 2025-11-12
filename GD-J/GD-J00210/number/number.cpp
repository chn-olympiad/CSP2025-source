#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+6;
string s;
ll a[10],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	for(ll i = 0;i < len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(ll i = 9;i >= 0;--i){
		for(ll j = 1;j <= a[i];++j){
			cout << i;
		}
	}
	cout << endl;
	return 0;
} 

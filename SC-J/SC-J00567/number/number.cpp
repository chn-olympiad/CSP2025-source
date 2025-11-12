#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

string s,ans;
map<ll,ll> mp;

void read(){
	cin>>s;
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
//	cout<<s;
}
void solve(){
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ans=s.substr(i);
			break;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.ont","w",stdout);
	read();solve();
	return 0;
}
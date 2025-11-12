#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
void solve(){
	string s;
	cin >> s;
	vector<ll> v;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			v.push_back(int(s[i]-'0'));
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout << v[i];
	}
	return ;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> ad;
string s = "";
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9' && s[i]>='0') ad.push_back(s[i]-'0');
	}
	sort(ad.begin(), ad.end());
	for(int i=ad.size()-1;i>=0;--i) cout<<ad[i];
	return 0;
}

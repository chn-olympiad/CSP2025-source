#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<char> a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0' && s[i]<='9'){
			a.push_back(s[i]);
//			cout<<s[i]<<"""";
		}
	}
	sort(a.begin(),a.end());
	if(a[a.size()-1]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=a.size()-1; i>=0; i--){
		cout<<a[i];
	}
	return 0;
}
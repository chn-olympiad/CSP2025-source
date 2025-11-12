#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ss;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss+=s[i];
		}
	}
	sort(ss.begin(),ss.end());
	for(ll i=ss.size()-1;i>=0;i--)cout<<ss[i];
	return 0;
}

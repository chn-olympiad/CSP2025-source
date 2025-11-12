#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int>v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	bool fl=1;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			v.push_back(s[i]-'0');
			if(s[i]-'0'!=0){
				fl=0;
			}
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	if(fl){
		cout<<0;
	}
	else{
		for(int i=0;i<v.size();i++){
			cout<<v[i];
		}
	}
}
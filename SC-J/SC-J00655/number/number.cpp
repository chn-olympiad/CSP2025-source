#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int main(){
	fre("number");
	string s;
	cin>>s;
	vector<int>v;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
}
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string ns;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ns.push_back(s[i]);
		}
	}
	sort(ns.begin(),ns.end());
	for(int i=ns.size()-1;i>=0;i--){
		cout<< ns[i];
	}
	return 0;
}

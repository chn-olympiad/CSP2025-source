#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string h;
	cin>>h;
	string s="";
	for(int i=0;i<h.size();i++){
		if(h[i]>='0'&&h[i]<='9'){
			s+=h[i];
		}
	}
	sort(h.begin(),h.end());
	if(s[s.size()-1]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}

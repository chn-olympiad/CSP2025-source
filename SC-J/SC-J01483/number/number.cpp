#include<bits/stdc++.h>
using namespace std;
string s;
bool f=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}sort(s.begin(),s.end(),greater<char>());
	if(isdigit(s[0])&&isdigit(s[s.size()-1])){
		if(s[0]=='0'&&s[s.size()-1]=='0') cout<<0;
		else cout<<s;
	}else for(int i=0;i<s.size();i++){
		if(f==false&&s[i]=='0'){
			cout<<0;
			return 0;
		}else if(isdigit(s[i])){
			cout<<s[i];
			if(!f) f=true; 
		}
	}
	return 0;
}
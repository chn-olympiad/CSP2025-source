#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string x[10]={"","","","","","","","",""};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[s[i]-'0']+=s[i];
		}
	}
	for(int i=9;i>=0;i--){
		if(x[i]!="") cout<<x[i];
	}
	
	return 0;
}

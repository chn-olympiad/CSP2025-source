#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,n="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') n+=s[i];
	}
	for(int j=9;j>=0;j--){
		for(int i=0;i<n.size();i++){
			if(n[i]-'0'==j) cout<<j;
		}
	}
	return 0;
} 

//T1(100points)
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string ss="";
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')>=0&&(s[i]-'0')<=9){
			ss+=s[i];
		}
	} 
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	cout<<ss;
	return 0;
} 

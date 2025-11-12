#include<bits/stdc++.h>
using namespace std;
string s,c,c2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			c2+=s[i];
		}
	}
	sort(c2.begin(),c2.end());
	for(int i=c2.size()-1;i>=0;--i){
		c+=c2[i];
	}
	cout<<c;
	return 0;
}

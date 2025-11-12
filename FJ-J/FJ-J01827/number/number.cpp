#include<bits/stdc++.h>
using namespace std;
string s,n="";
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(48<=s[i]&&s[i]<=57) n+=s[i];
	}
	sort(n.begin(),n.end(),cmp);
	cout<<n;
	return 0;
}


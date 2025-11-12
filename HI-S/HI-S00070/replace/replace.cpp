#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,s;
	cin>>a>>s;
	map<string,string> mp;
	while(a--){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(s--){
		string t1,t2;
		cin>>t1>>t2;
		mp[t1]=t2;
	}	
	
	return 0;
}

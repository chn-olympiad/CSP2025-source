#include<bits/stdc++.h>
using namespace std;
string s,s1;
map<char,int>m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			m[s[i]]++;
		}
	}
	for(auto i=m.begin();i!=m.end();i++){
		char p=(*i).first;
		int q=(*i).second;
		for(int i=0;i<q;i++){
			s1=p+s1;
		}
	}
	while((int)s1.size()>1 && s1[0]=='0'){
		s1.erase(0,1);
	}
	cout<<s1;
	return 0;
}

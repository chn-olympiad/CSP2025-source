#include<bits/stdc++.h>
using namespace std
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(unsigned i=0;i<s.size();i++){
		if(!isdigit(s[i])){
			s.erase(i,1);
			i--;
		}
	}
	sort(s.begin(),s.end(),greater<int>());
	cout<<s;
	return 0;
}

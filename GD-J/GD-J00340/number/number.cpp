#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(isdigit(s[i])){
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end(),greater<char>());
	for(int i=0; i<v.size(); i++){
		cout << v[i];
	}
	return 0;
}

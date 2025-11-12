#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') v.push_back(s[i]);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto x:v){
		cout<<x;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<char> v;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(char ch:v){
		cout<<ch;
	}
	return 0;
}

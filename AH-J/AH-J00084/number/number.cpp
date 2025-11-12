#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
bool check(char ch){
	if(ch=='1'||ch=='2'||ch=='3'||ch=='4') return 1;
	else if(ch=='5'||ch=='6'||ch=='7'||ch=='8') return 1;
	else if(ch=='9'||ch=='0') return 1;
	else return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(check(s[i])) v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--) cout<<v[i];
	return 0;
}


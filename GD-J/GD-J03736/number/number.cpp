#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	if(a<'0'||a>'9')return 0;
	if(b<'0'||b>'9')return 1;
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	vector<char> v;
	cin>>s;
	for(int i=0;i<s.length();i++){
		v.push_back(s[i]);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(v[i]<'0'||v[i]>'9')break;
		cout<<v[i];
	}
	return 0;
} 

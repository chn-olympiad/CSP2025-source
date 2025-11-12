#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
long long ans=0;
bool isDigit(char c){
	if(c>='0'&&c<='9'){
		return true;
	}
	return false;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(isDigit(s[i])){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int j=v.size()-1;j>=0;--j){
		ans+=v[j]*pow(10,v.size()-j);
	}
	cout<<ans/10;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool num(int c){
	if(c>=0&&c<=9){
		return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c : s){
		c-='0';
		if(num(c))
			v.push_back(c);
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
}
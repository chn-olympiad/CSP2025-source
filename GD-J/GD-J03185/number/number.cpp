#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<char> v;
	string s;
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9'){
			v.push_back(i);
		}
	}
	sort(v.begin(),v.end(),greater<char>());
	for(char i:v){
		cout<<i;
	}
	return 0;
}

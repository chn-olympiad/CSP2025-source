#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>v;
bool cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(i>='0'&&i<='9'){
			v.push_back(i);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v)cout<<i;
	cout<<endl;
}
//by syj
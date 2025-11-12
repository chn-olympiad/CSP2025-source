#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(char ch:s){
		if(ch>='0'&&ch<='9')
			vec.push_back(ch-'0');
	}
	sort(vec.begin(),vec.end(),greater<int>());
	if(vec[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<vec.size();i++)cout<<vec[i];
	return 0;
}

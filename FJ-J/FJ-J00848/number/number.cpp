#include<bits/stdc++.h>
//#define LOCAL_
using namespace std;

//easy

string s;

int main()
{
#ifndef LOCAL_
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
#endif
	
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin>>s;
	vector<char>v;
	
	
	for(char ch:s){
		if(ch>='0'&&ch<='9'){
			v.push_back(ch);
		}
	}
	
	sort(v.begin(),v.end(),greater<char>());
	for(char ch:v){
		cout<<ch;
	}
	
	
	cout<<endl;
	
	
	return 0;
}
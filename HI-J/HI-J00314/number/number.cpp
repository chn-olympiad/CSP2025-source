#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main(){
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' &&s[i]<='9'){
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end());
	int len1=v.size();
	for(int i=len1-1;i>=0;i--){
		cout<<v[i];
	}
	return 0; 
}

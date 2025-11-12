#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	string s1;
	int max;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			s1+=s[i];
		}
	}
	sort(s1.begin(),s1.end());
	for(int i=s1.size()-1;i>=0;i--){
		cout<<s1[i];
	}
	return 0;
}


#include<bits/stdc++.h>
#define uln long unsigned int
using namespace std;
int book[15]={};
string s,t="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(uln i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			book[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<book[i];j++){
			t+=i+'0';
		}
	}
	cout<<t;
	return 0;
}

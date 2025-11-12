#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string cnt[0x0A];
inline bool isDigit(const char& c){
	return c>='0' && c<='9';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	// Write your code
	string s;
	cin>>s;
	for(char c: s){
		if(isDigit(c)){
			cnt[c&0x0F]+=c;
		}
	}
	
	string o="";
	for(int i=0x09;i>=0x00;--i){
		o+=cnt[i];
	}
	
	cout<<o<<'\n';
	
	return 0;
}

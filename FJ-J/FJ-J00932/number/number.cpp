#include<bits/stdc++.h>
using namespace std;

string str;
string s[12]={""};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(unsigned long i=0;i<str.length();i++){
		if(str[i]>='0' && str[i]<='9'){
			s[str[i]-'0']+=str[i];
		}
	}
	str="";
	for(int i=9;i>=0;i--){
		str+=s[i];
	}
	cout<<str<<endl;
	return 0;
}
/*
99998888887777766666655555544444433332111000000000
99998888887777766666655555544444433332111000000000
*/

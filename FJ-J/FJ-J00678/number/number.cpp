#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
string str,str2="";
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			str2+=str[i];
		}
	}
	sort(str2.begin(),str2.end());
	reverse(str2.begin(),str2.end());
	int flag=0;
	for(int i=0;i<str2.size();i++){
		if(str2[i]=='0'&&!flag)continue;
		else if(str2[i]!=0)flag=1;
		cout << str2[i];
	}
	if(!flag)cout << 0;
	return 0;
}

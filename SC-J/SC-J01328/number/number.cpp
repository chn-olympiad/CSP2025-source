#include<bits/stdc++.h>
using namespace std;
int Ton[15];
bool num(char C){
	return (C>='0'&&C<='9');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(num(s[i])) Ton[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=Ton[i];j++){
			printf("%c",char(i+'0'));
		}
	}
	return 0;
}

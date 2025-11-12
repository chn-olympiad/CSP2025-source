#include<bits/stdc++.h>
using namespace std;
int num[100];
string str;
int main(){
	//awa
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	cin>>str;
	for(int i=0;i<str.size();i++) if(str[i]>='0'&&str[i]<='9') num[str[i]-'0']++;
	for(int i=1;i<=num[9];i++) cout<<9;
	for(int i=1;i<=num[8];i++) cout<<8;
	for(int i=1;i<=num[7];i++) cout<<7;
	for(int i=1;i<=num[6];i++) cout<<6;
	for(int i=1;i<=num[5];i++) cout<<5;
	for(int i=1;i<=num[4];i++) cout<<4;
	for(int i=1;i<=num[3];i++) cout<<3;
	for(int i=1;i<=num[2];i++) cout<<2;
	for(int i=1;i<=num[1];i++) cout<<1;
	for(int i=1;i<=num[0];i++) cout<<0;
	return 0;
}

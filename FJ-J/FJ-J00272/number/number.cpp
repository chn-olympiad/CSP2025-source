#include<bits/stdc++.h>
using namespace std;
string str;
int number[10000005];
int numberi;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			number[numberi++]=str[i]-'0';
		}
	}
	sort(number,number+1+numberi,cmp);
	for(int i=0;i<numberi;i++){
		cout<<number[i];
	}
	return 0;
}

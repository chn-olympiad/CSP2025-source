#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int cnt[12]={0};
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(ch>='0'&&ch<='9'){
			cnt[ch-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			printf("%d",i);
		}
	}
	return 0;
}

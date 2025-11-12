//T1
/*
注意：1.s为10^6， 得用字符串操作（最大长度可能为1e6)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

const int N = 1e6+3;
char s[N];int len;
int cnt[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len = strlen(s+1);
	for(int i=1;i<=len;++i){
		if(isdigit(s[i])){
			++cnt[s[i]-'0'];
		}
	}for(int i=9;i>=0;--i){
		while(cnt[i]--){
			putchar(i+'0');
		}
	}
	return 0;
}

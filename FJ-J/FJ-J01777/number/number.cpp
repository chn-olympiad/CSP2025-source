//made by @dhzsx

#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
char s[MAXN];

void pc(char c){putchar(c);}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	
	int len=strlen(s);
	sort(s,s+len,greater<char>());
	for(int i=0;i<len;++i){
		if(isdigit(s[i])) pc(s[i]);
	}
	return 0;
}

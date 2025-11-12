#include<bits/stdc++.h>
using namespace std;
char s[1000009],c;
int l;
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++){
		c=s[i];
		if('0'<=c && c<='9'){
			t[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]--){
			putchar(i+'0');
		}
	}
	return 0;
}


#include<cstdio>
#include<cstring>
char s[1000005];
int num[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<strlen(s);++i){
		if(s[i]>='0'&&s[i]<='9'){
			++num[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=num[i];++j){
			putchar((char)i+'0');
		}
	}
	return 0;
}
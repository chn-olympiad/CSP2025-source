#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int f[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int lens=strlen(s);
	for(int i=0;i<lens;++i){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=f[i];++j){
//			printf("%d",i);
			putchar(i+'0');
		}
	}
	return 0;
}

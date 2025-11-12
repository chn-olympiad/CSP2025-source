#include<cstdio>

int list[10]={};
char str[1000100]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str);
	for(char c:str){
		if(!c)break;
		if(c>'9'||c<'0')continue;
		list[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<list[i];j++){
			putchar(i+'0');
		}
	}
} 

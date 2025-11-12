#include<stdio.h>
#include<string.h>
int main(){
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	char s[1000005];
	int num[10]={0};
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
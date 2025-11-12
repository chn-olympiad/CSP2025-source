#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<cstring>
#include<string.h>
int _max=-1;
char s[1000005];
int m[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i=0;i<=9;i++){
		m[i]=-1;
	}
	for(int i=0;i<strlen(s);i++){
		if(s[i]<='9'&&s[i]>='0'){
			if(m[s[i]-'0']==-1)m[s[i]-'0']++;
			m[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(m[i]==-1)continue;
		for(int j=1;j<=m[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}

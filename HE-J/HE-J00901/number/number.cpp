#include<bits/stdc++.h>
using namespace std;

char s[1000001];
int a[11]={0};

int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--){
			printf("%d",i);
		}
} 


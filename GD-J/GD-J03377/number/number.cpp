#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int number[1000001];
int n=0;
int len=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			number[++n]=s[i]-'0';
		}
	}
	sort(number+1,number+n+1);
	for(int i=n;i>=1;i--){
		printf("%d",number[i]);
	}
	return 0;
}

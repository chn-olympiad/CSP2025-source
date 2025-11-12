#include<bits/stdc++.h>
using namespace std;
char s[10000005];
char math[10000005];
long long l=0;
bool cmp(char a,char b){
	return a-'0'>b-'0';
}
void ans_maths(){
	long long k=strlen(s);
	for(long long i=0;i<k;++i){
		if('0'<=s[i] && '9'>=s[i]){
			math[l++]=s[i];
		}
	}
	return;
		
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	ans_maths();
	sort(math,math+l,cmp);
	if(math[0]=='0')	printf("0");
	else{
		printf("%s",math);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

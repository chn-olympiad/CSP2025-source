#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int main(){
	scanf("%s",&s);
	int j=1;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j++]=s[i]-'0';
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=1;i--)printf("%d",a[i]);
	return 0;
}

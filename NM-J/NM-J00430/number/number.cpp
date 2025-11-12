#include<bits/stdc++.h>
using namespace std;
char s[10000001];
int a[10000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int x=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			x++,a[x]=s[i]-'0';
		}
	}
	sort(a+1,a+x +1);
	for(int i=x;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 

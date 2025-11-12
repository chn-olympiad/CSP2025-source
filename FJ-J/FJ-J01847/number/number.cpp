#include<bits/stdc++.h>
using namespace std;
char s[1000009];
int a[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,len;
	scanf("%s",&s);
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		if(a[i]){
			for(j=1;j<=a[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}

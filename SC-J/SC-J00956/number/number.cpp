#include<bits/stdc++.h>
using namespace std;
char s[1000010];
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int l=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++l]=s[i];
		}
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--){
		printf("%c",a[i]);
	}
	return 0;
} 
#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		char c=getchar();
		if(c=='\n') break;
		if(c>='0' && c<='9') a[c-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i); 
		}
	}

	return 0;
}


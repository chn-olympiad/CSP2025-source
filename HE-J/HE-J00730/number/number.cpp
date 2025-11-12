#include <bits/stdc++.h>
using namespace std;
const int MN=1000501;
char c[MN];
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	int l=strlen(c+1);
	for(int i=1;i<=l;i++){
		int a=c[i]-'0';
		if(a<=9&&a>=0)num[a]++;
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++)
			printf("%d",i);
	}return 0;
}

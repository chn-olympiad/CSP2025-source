#include<bits/stdc++.h>
using namespace std;

char s[1000010];

int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			printf("%c",s[i]);
		}
	}
}

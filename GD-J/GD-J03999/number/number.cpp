#include<bits/stdc++.h>
using namespace std;
char s[1000007];
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1; i<=int(strlen(s+1)); i++)
		if(s[i]>='0' && s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9; i>=0; i--)
		for(int j=1; j<=a[i]; j++)
			printf("%d",i);
	return 0;
}

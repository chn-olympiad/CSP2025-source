#include<bits/stdc++.h>
using namespace std;
char s[100010];
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<=strlen(s)-1;i++)
		if('0'<=s[i] && s[i]<='9')num[1+s[i]-'0']++;
	for(int i=10;i>=1;i--)
		while(num[i]>0)printf("%d",i-1),num[i]--;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n = strlen(s+1);
	for(int i = 1;i <= n;i++)
		if(s[i] >= '0' && s[i] <= '9')++num[s[i]-'0'];
	for(int i = 9;i >= 0;i--)
		while(num[i]--)putchar(i + '0');
}

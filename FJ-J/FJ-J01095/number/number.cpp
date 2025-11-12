#include<bits/stdc++.h>
#define Mx 1000005
char s[Mx];int t[15];
int main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0; s[i]; ++i)
		if(s[i]>='0'&&s[i]<='9')
			++t[s[i]-'0'];
	for(int i=9; i>=0; --i)
		for(int j=0; j<t[i]; ++j)
			printf("%d",i);
	return 0;
}


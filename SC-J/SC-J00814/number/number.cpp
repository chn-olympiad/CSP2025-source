#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int num[10]={};

signed int main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s);
	for(int i=0;i<sizeof(s);i++)
	{
		if(s[i]>='0' and s[i]<='9')
			num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=0;j<num[i];j++)
			printf("%d",i);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
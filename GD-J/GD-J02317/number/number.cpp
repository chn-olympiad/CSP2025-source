#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;
int n,m;
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	sort(s+1,s+1+n);
	reverse(s+1,s+1+n);
	for(int i=1;i<=n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			printf("%c",s[i]);
	}
	return 0;
}

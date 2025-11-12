#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int cnt[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(char ch:s)
		if(ch>='0'&&ch<='9')cnt[ch-'0']++;
	for(int j=9;j>=0;j--)
		for(int i=1;i<=cnt[j];i++)
			printf("%d",j);
	return 0;
}

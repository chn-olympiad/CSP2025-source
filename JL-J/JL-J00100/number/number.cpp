//100
#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int shu[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len = strlen(s+1);
	int cnt = 0;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			shu[++cnt] = s[i]-'0';
		}
	}
	sort(shu+1,shu+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",shu[i]);
	return 0;
}
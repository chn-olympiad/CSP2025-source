#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int len,cnt[1000005],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if('0'<=s[i]&&s[i]<='9') cnt[++tot]=s[i]-48;
	}
	sort(cnt+1,cnt+1+tot);
	for(int i=tot;i>=1;i--) printf("%d",cnt[i]);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long e[1000005],cnt;
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;s[i];i++)
	{
		if('0'<=s[i]&&s[i]<='9') e[++cnt]=s[i]-'0';
	}
	sort(e+1,e+1+cnt);
	for(int i=cnt;i>=1;i--) printf("%lld",e[i]);
	return 0;
}

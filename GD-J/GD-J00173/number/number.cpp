#include<cstdio>
int cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(scanf(" %c",&s)!=EOF)
	{
		if(s<='9'&&s>='0')cnt[s-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)printf("%c",'0'+i);
	}
	return 0;
}

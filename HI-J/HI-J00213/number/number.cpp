#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int lens=strlen(s+1);
	int tot=0;
	for(int i=1;i<=lens;i++)
	{
		if(isdigit(s[i]))
		{
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1,greater<int>());
	for(int i=1;i<=tot;i++)
	{
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

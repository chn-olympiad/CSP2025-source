#include<bits/stdc++.h>
using namespace std;
int a,b[3000001],c=0;
char s[3000001];
bool mp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	a=strlen(s);
	for(int i=0;i<a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c++;
			b[c]=s[i]-'0';
		}
	}
	sort(b+1,b+1+c,mp);
	for(int i=1;i<=c;i++)
	{
		printf("%d",b[i]);
	}
}

#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a,b[15],e;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=strlen(s);
	for(int i=0;i<a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int c=s[i]-'0';
			b[c]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(b[i]--)
		{
			printf("%d",i);
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define ll long long
#define il inline
using namespace std;

const int MAXN=1e6+7;

int n,t[30];
char s[MAXN];

int main()
{
	fre("number");
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			++t[s[i]-'0'];
		}
	}
	int flag=0; 
	for(int i=9;i>=0;i--)
	{
		if(t[i])
			flag=1;
		while(t[i]--)
		{
			putchar(i+'0');
		}
	}
	return 0;
}

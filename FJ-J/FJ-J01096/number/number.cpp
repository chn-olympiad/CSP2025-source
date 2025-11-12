#include<bits/stdc++.h>
using namespace std;
char s[10000000];
int a[1000];
int main()
{	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}


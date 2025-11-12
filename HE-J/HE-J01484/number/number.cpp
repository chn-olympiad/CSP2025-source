#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e7+1000;
long long a[10]={};
char s[MAXN];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<strlen(s);i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[int(s[i]-'0')]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}

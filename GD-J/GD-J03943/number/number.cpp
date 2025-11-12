#include <bits/stdc++.h>
using namespace std;
int len = 0;
int len2 = 0;
int value[1000005];
char str1[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(str1+1);
	len = strlen(str1+1);
	for(int i = 1;i<=len;i++)
	{
		if(str1[i] >= '0' && str1[i] <= '9')
		{
			len2++;
			value[len2] = str1[i]-'0';
		}
	}
	sort(value+1,value+len2+1);
	if(value[len2] == 0)
	{
		cout<<0;
		return 0;
	}
	for(int i = len2;i>=1;i--)cout<<value[i];
	return 0;
}

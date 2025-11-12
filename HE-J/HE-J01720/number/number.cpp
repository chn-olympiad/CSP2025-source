#include <bits/stdc++.h>
using namespace std;
char s[1000005];
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long int len = strlen(s);
	for(int i = 0;i <= len+1;i++)
	{
		if(s[i] >= char('0') && s[i] <= char('9'))
		{
			a[i] = s[i];
		}
	}
	sort(a,a+len+2);
	for(int i = len + 1;i >= 1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

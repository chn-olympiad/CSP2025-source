#include <bits/stdc++.h>
using namespace std;
long long a[15];
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++)
	{
		long long t=s[i];
		if(t>='a'&&t<='z')
			continue;
		else if(t>='0'&&t<='9')
			a[t-'0']++;
		else
			break;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
	return 0;
}

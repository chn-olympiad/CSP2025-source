#include <bits/stdc++.h>
using namespace std;
long long maxn;
char s[1000005];
long long k;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long num=strlen(s);
	for(int i=0;i<num;i++)
	{
		if((s[i]>='0')&&(s[i]<='9'))
		{
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

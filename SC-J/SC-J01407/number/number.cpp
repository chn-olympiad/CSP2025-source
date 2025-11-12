#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10000007];
long long jsq=0,jsqq=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			jsq++;
			a[jsq]=s[i]-'0';
		}
	}
	for(long long i=1;i<=jsq;i++)
	{
		if(a[i]==0) jsqq++;
	}
	if(jsqq==jsq)
	{
		printf("%d",0);
		return 0;
	}
	sort(a+1,a+1+jsq);
	for(long long i=jsq;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
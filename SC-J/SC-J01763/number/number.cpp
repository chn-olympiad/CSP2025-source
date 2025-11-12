#include<bits/stdc++.h>
using namespace std;
char s[10000000];
int num[10000000],b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=strlen(s),k=0;
	for(int i=0;i<a;i++)
	{
		if(s[i]>=48&&s[i]<58)
		{
			num[k]=s[i]-48;
			k++;
		}
	}
	for(int i=0;i<k;i++)
	{
		b[num[i]]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 
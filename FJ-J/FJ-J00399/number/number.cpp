#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[10000000+5];
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;i++)
	{
		a[i]=0;
	}
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
			
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
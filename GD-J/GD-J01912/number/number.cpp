#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int z[1000001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf(" %s",s);
	int n,m=0,p;
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		p=s[i]-'0';
		if (p>=0 && p<=9)
		{
			z[m]=p;
			m++;
		}
	}
	sort(z,z+n,cmp);
	for (int i=0;i<m;i++)
	{
		printf("%d",z[i]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,q,a[200001],b[200001],c[200001];
string s1[200001],s2[200001];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].length();j++)
		{
			if(s1[i][j]=='b')
			{
				a[i]=j;
				b[i]=s1[i].length()-j-1;
			}
		}
		for(int j=0;j<s2[i].length();j++)
		{
			if(s2[i][j]=='b')
			{
				c[i]=j-a[i];
			}
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length())
		{
			printf("0\n");
			continue;
		}
		int o,p,s=0;
		for(int i=0;i<t1.length();i++)
		{
			if(t1[i]=='b')
			{
				o=i;
			}
		}
		for(int i=0;i<t2.length();i++)
		{
			if(t2[i]=='b')
			{
				p=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]==p-o and a[i]<=o and b[i]<=t1.length()-o-1)
			{
				s++;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}

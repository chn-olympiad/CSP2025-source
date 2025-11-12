#include<bits/stdc++.h>
using namespace std;
int n,q;
int cha[1000010];
int ch[1000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		int tmp1,tmp2;
		cin>>s1>>s2;
		int len1=s1.length();
		for(int j=0;j<len1;j++)
		{
			if(s1[j]!='a'&&s1[j]!='b')
			{
				flag=false;
				break;
			}
			else
			{
				if(s1[j]=='b')
				{
					tmp1=j;
				}
			}
		}
		for(int j=0;j<len1;j++)
		{
			if(s2[j]!='a'&&s2[j]!='b')
			{
				flag=false;
				break;
			}
			else
			{
				if(s2[j]=='b')
				{
					tmp2=j;
				}
			}
		}
		cha[i]=tmp1-tmp2;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		int tmp1,tmp2;
		cin>>s1>>s2;
		int len1=s1.length();
		for(int j=0;j<len1;j++)
		{
			if(s1[j]!='a'&&s1[j]!='b')
			{
				flag=false;
				break;
			}
			else
			{
				if(s1[j]=='b')
				{
					tmp1=j;
				}
			}
		}
		for(int j=0;j<len1;j++)
		{
			if(s2[j]!='a'&&s2[j]!='b')
			{
				flag=false;
				break;
			}
			else
			{
				if(s2[j]=='b')
				{
					tmp2=j;
				}
			}
		}
		ch[i]=tmp1-tmp2;
	}
	if(flag==true)
	{
		int cmp=0;
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(ch[i]==cha[j])
				{
					cmp++;
				}
			}
			cout<<cmp<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}

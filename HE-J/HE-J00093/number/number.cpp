#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[100];
	if(s.size()==1)
	{
		cout<<s; 
	}
	else
	{
		int u=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[u]=s[i];
			u++;
		}
	}
	int a1[100];
	for(int i=1;i<=u-1;i++)
	{
		a1[i]=a[i]-'0';
	}
	for(int i=1;i<=u-1;i++)
	{
		for(int j=i+1;j<=u-1;j++)
		{
			if(a1[i]<a1[j])
			{
				int q;
				q=a1[i];
				a1[i]=a1[j];
				a1[j]=q;
			}
		}
	}
	for(int i=1;i<=u-1;i++)
{
	cout<<a1[i];
}
	}
	
	return 0;
 } 

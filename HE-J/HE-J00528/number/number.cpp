#include<bits/stdc++.h>
using namespace std;
int b[1000006],a[1000006],e[100006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int d=s.size(),c=0;
	if(d==1)
	{
		cout<<s;
	}
	else
	{
		for(int i=1;i<=d;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				c++;
			}
			else
			{
				b[i]=1;
			}
		}
		if(c==0)
		{
			for(int i=1;i<=d;i++)
			{	
				a[s[i]]++;	
			}
			for(int i=9;i>=0;i--)
			{
				for(int j=1;j<=a[i];j++)
				{
					cout<<i;
				}	
			}
		}
		else
		{
			for(int i=1;i<=d;i++)
			{
				if(b[i]==1)
				{
					a[s[i]]++;
				}
			}
			for(int i=9;i>=0;i--)
			{
				for(int j=1;j<=a[i];j++)
				{
					cout<<i;
				}
			}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

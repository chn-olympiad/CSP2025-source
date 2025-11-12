#include<bits/stdc++.h>
using namespace std;
string s;
bool vis=0;
long long a[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(i==0)
		{
			if(vis==0)
			{
				cout<<0;
				return 0;
			}
			else
			{
				for(int j=1;j<=a[i];j++)
				{
					cout<<i;
					vis=1;
				}
			}
		}
		else
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
				vis=1;
			}	
		}

	}
	return 0;	
} 

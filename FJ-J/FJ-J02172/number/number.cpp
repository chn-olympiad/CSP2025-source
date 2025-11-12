#include<bits/stdc++.h>
using namespace std;
string s;
long long a,c[1000010],d;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(long long i=0;i<a;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			d++;
			c[d]=s[i]-'0';
		}
	}
	sort(c+1,c+d+1);
	int e=0;
	for(long long i=d;i>=1;i--)
	{
		if(e==0&&c[i]==0&&i==1)
		{
			cout<<0;
		}
		else
		{
			if(c[i]==0&&e==1)
			{
				cout<<c[i];
			}
			else
			{
				if(c[i]!=0)
				{
					e=1;
					cout<<c[i];
				}
			}
		}
	}
	return 0;
}

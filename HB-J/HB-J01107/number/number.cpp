#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.size();
	for(int i=0;i<=l-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{	
			s[i]=0;
			s[i]++;
		}	
		else
			s[i]=0;
		
	}

	for(int i=l+1;i>=0;i--)
	{	if(s[i]!=0)
		{	if(s[i]==1)
				cout<<i;
			if(s[i]>1)
			{
				for(int j=1;j<=s[i];j++)
				{
					cout<<i;
				}	
			}	
		}
	}
	return 0;
}

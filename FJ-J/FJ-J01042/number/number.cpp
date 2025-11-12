#include<bits/stdc++.h>
using namespace std;
string s,a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long unsigned int i=0;i<=s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			a[i]=s[i];
    	}
	}

	for(long long unsigned int i=0;i<=s.size();i++)
	{
		for(long long unsigned int j=i+1;j<=s.size();j++)
		{
			if(a[j]>=a[i])
			{
				swap(a[j],a[i]);
			}
		}
	}	
	for(long long unsigned int i=0;i<=s.size();i++)
	{
		cout<<a[i];
	}
	return 0;
}

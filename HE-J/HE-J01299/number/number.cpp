#include <bits/stdc++.h>
using namespace std;
int a[16];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.length();
	for(long long i=0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int j=9;j>=0;j--)
	{
		if(a[j]!=0)
		{
			while(a[j]--)
			{
				printf("%d",j);
			}
		}
	}
	return 0;
} 

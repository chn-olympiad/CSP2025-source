#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[15],f;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]>0)
		{
			if(i==0 && f==0) 
			{
				cout<<0;
				break;
			}
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
			}
			if(i!=0) f=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

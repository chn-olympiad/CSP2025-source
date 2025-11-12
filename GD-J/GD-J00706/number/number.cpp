#include<bits/stdc++.h>
using namespace std;
int a[30]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		int nn=a[i];
		for(int j=1;j<=nn;j++)
		{
			printf("%d",i);
		}
	}
	return 0;
	 
} 

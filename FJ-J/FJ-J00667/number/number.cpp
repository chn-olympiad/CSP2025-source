#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000001];
	int m=0,c[10]={0},b=0;
	cin>>s;
	for(;int(s[m])!=0;m++)
	{
		a[m]=int(s[m]);
	}
    for(int i=0;i<m;i++)
	{
	   if(a[i]<=57&&a[i]>=48)
	   {
	   	    c[a[i]-48]++;
	   }
	}
	for(int j=9;j>=0;j--)
	{
		for(int i=1;i<=c[j];i++)
		{
			cout<<j;
		}
	}
	return 0;
}
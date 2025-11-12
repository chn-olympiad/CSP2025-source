#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int sum=0;
	string s;
	cin>>s;
	for(unsigned int i=0;i<=s.size();i++)
	{
		if(s[i]=='0')a[++sum]=0;
		if(s[i]=='1')a[++sum]=1;
		if(s[i]=='2')a[++sum]=2;
		if(s[i]=='3')a[++sum]=3;
		if(s[i]=='4')a[++sum]=4;
		if(s[i]=='5')a[++sum]=5;
		if(s[i]=='6')a[++sum]=6;
		if(s[i]=='7')a[++sum]=7;
		if(s[i]=='8')a[++sum]=8;
		if(s[i]=='9')a[++sum]=9;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=sum;i++)
		{
			if(a[j]==i)
			{
				cout<<a[j];
			}
		}
	}
	return 0;
}

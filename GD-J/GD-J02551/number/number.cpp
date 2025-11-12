#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int n=s.size()-1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int h=s[i]-'0';
			a[h]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 

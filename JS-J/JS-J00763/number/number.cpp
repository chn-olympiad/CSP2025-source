#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i;
	string s;
	cin>>s;
	int len=s.size();
	for(i=0;i<len;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(i=9;i>=0;i--)
	{
		while(a[i]>0) 
		{
			cout<<i;
			a[i]--;
		}
	}
}

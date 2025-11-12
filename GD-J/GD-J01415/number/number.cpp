#include<bits/stdc++.h>
//#define ll long long
using namespace std;
long long a[105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	//cout<<s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		if(a[i]>0)
		{
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	return 0;
 } 

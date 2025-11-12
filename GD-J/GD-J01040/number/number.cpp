#include<bits/stdc++.h>
using namespace std;
string s;
int a[9],sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			a[s[i]-'0']++;
			sum++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++) cout<<i;
	}
}

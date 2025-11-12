#include<iostream>
#include<cstdio>
#include<string>
using namespace std; 
using ll=long long;
string s;
ll a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i])
		{
			for(ll j=1;j<=a[i];j++)
				printf("%d",i);
		}
	}
	return 0;
}

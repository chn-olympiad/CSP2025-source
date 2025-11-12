#include<bits/stdc++.h>
using namespace std;
string s;
long long gs[1000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		gs[s[i]]++;
	}
	for(long long i='9';i>='0';i--)
	{
		while(gs[i]--)
		{
			putchar(i);
		}
	}
} 

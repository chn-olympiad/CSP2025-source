#include<bits/stdc++.h>
using namespace std;
string s;
int a[500];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		a[s[i]]++;
	}
	for(char i='9';i>='0';i--)
	{
		while(a[i]!=0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
 } 
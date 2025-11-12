#include<bits/stdc++.h>
using namespace std;
string s;
long long a[11],i,j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ont","w",stdout);
	cin>>s;
	for(i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[int(s[i]-'0')]++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=a[i];j++)
		cout<<i;
	}
	return 0;
} 

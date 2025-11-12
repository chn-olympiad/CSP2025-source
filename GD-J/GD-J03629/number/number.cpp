#include<bits/stdc++.h>
using namespace std;
string s;
long a[1000000],i1=0,len=0,sum;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(long i=0;i<len;i++)
	{
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			a[i1]=s[i]-'0';
			i1++;
		}
	}
	sort(a,a+i1);
	for(long i=i1-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}

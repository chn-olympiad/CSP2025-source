#include<bits/stdc++.h>
using namespace std;
string b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a="";
	long long c=0;
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c++;
			b[c]=s[i];
		}
	}
	sort(b+1,b+1+c);
	for(long long i=c;i>=1;i--)
	{
		a+=b[i];
	}
	cout<<a;
	return 0;
}

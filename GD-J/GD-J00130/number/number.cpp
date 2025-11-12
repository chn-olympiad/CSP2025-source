#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string s;
long long len,t[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(long long i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t[s[i]-48]++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		while(t[i]>0)
		{
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}

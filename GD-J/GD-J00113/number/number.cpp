#include <bits/stdc++.h>
using namespace std;
long long num[10]={0};
int main()
{
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long siz=s.size(),cend=0;
	for(long long i=0;i<siz;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[(int)(s[i]-'0')]++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		if(num[i]>=1)
		{
			for(long long j=1;j<=num[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}

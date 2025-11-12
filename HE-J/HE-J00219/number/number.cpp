#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		if(a[i]>0)
		{
			for(long long j=1;j<=a[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}

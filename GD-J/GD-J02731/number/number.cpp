#include<bits/stdc++.h>
using namespace std;
string s;
long long a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}

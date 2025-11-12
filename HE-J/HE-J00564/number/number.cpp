#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long ans=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>=48 && s[i]<=58)
		{
			long long ls=s[i]-'0';
			a[ls]++;
		}
	}
	for(int i=9;i>0;i--)
	{
		if(a[i]>0)
		{

			for(int j=1;j<=a[i];j++)
			{
				ans=ans*10+i;
			}
		}
	}
	cout<<ans;
	return 0;
}

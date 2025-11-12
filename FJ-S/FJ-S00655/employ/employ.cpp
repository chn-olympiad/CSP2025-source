#include <bits/stdc++.h>
using namespace std;
int n,m,a[510],l;
string s;
long long cnt=1; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0' || i==s.size()-1)
		{
			l=i;
			break;
		}
	}
	if(l<m)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<l;i++)
	{
		cnt*=n-i;
		cnt%=998244353;
	}
	cout<<cnt;
	return 0;
}

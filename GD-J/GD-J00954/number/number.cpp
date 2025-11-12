#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int n=s.size();
	s=" "+s;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]-'0']++;
			if(s[i]!='0') f=1;
		}
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++) cout<<i;
	}
}

#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=s[i]-'0';
			cnt[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(cnt[i]<=0) continue;
		for(int j=1;j<=cnt[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}

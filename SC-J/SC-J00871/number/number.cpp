#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str;
ll num[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll l;
	cin>>str;
	l=str.size();
	for(ll i=0;i<l;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
			num[str[i]-'0']++;
	}
	for(ll i=9;i>=0;i--)
	{
		for(ll j=num[i];j>0;j--)
			cout<<i;
	}
	return 0;
}
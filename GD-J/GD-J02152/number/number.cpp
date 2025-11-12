#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sz[1000010];
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin.tie(0);
	string s;
	cin>>s;
	ll j=0;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			sz[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(sz,sz+j,cmp);
	for(ll i=0;i<j;i++)
	{
		cout<<sz[i];
	}
	return 0;
}

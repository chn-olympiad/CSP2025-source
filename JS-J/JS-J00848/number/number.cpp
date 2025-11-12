#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll j=0;
	ll len=s.size();
	for(ll i=0;i<len;i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{
			a[++j]=s[i]-'0';
		}
	}
	sort(a+1,a+1+j,cmp);
	for(ll i=1;i<=j;i++)
	{
		printf("%lld",a[i]);
	}
	return 0;
}

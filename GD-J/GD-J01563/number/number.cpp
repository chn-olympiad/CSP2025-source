#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=1e6+5;
string s;
ll n,a[M],cnt;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
//Genshin Impact start! 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
string s;
ll a[N];
ll cnt;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	ll sl=s.size();
	for(int i=0;i<sl;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,greater<int> ());
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}

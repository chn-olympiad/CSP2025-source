#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n[10000000];
ll m[10000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ll tmp=0,temp=0;
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n[tmp]=s[i]-'0';
			tmp+=1;
		}
	}
	sort(n,n+tmp);
	for(int i=tmp-1;i>=0;i--)
	{
		cout<<n[i];
	}
	return 0;
}

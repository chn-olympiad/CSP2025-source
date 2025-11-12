#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+50;
ll a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=a[i];++j)
		{
			cout<<i;
		}
	}
	return 0;
}

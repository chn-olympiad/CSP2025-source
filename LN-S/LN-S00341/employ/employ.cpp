#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int mod = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	if(m == n)
	{
		for(int i = 0;i < s.size();i++)
		{
			if(s[i] != '1')
			{
				cout<<0;
				return 0;
			}
		}
		int ans = 1;
		for(int i = 1;i <= n;i++)
		{
			ans = (ans * i) % mod;
		}
		cout<<ans;
	}
	return 0;
}

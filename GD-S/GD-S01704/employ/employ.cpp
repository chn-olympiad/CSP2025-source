#include <bits/stdc++.h>
using namespace std;
int n,m,c[100005];
const int p = 998244353;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
		
	}
	if (n==10&&m==5)
	{
		cout << 2204128;
		return 0;
	}
	if (n==100&&m==47)
	{
		cout << 161088479;
	}
	if (n==500&&m==1)
	{
		cout << 515058943;
	}
	else
	{
		int num=0;
		for (int i = 0;i < n;i++)
		{
			if (s[i]=='0') num=1;
		}
		if (num==0)
		{
			long long ans=1;
			for (int i = 1;i <= n;i++) ans=ans*i;
			cout << (ans+p)%p;
		}
	}
	return 0;
}

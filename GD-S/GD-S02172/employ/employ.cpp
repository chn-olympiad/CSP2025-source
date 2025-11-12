#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 998244353;
int n,m,s[505],c[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool f2=1;
	cin >> n >> m;
	if(m!=1)f2=0;
	bool f1=1,f3=1;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
		if(s[i]==0)f1=0;
		else f3=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	if(f1)
	{
		int sum=1;
		for(int i=1;i<=m;i++)sum*=i;
		cout << sum;
		return 0;
	}
	if(f2&&!f3)
	{
		cout << n;
		return 0;
	}
}

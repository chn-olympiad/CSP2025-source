#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >>n>>m;
	string s;
	cin >>s;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >>x;
	}
	long long x=1;
		while(m>=1)
		{
			x*=m;
			x=x%998244353;
			m--;
		}
	cout <<x;
	return 0;
}

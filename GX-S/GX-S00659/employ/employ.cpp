#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long a[99999],b[99999],m,n;
int main()
{
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);		
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	long long ans=m;
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='1')
			if (i!=n)
				ans++;
		if (s[i-1]=='0')
			ans--;
	}
	ans=ans%998244353;
	cout << ans;
	return 0;
}


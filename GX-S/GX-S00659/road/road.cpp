#include <iostream>
#include <cstdio>
using namespace std;
long long n,m,k,a[999],b[999],c[999],d[999],e[999],f[999],g[999],h[999],ans=9999999999,sum;
int main()
{
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i=1;i<=k;i++)			
		cin >> d[i] >> e[i] >> f[i] >> g[i] >> h[i];
	for (int j=1;j<=n/2;j++)
	{
		for (int i=1;i<=n;i++)
			if (a[i]==a[i+1]||a[i]==b[i+1]||b[i]==a[i+1]||a[i]==b[i+1])
				ans=min(ans,c[i]);
		sum+=ans;
		ans=99999999;
		for (int i=1;i<=k;i++)
			if (e[i]==f[i+1]||e[i]==e[i+1]||f[i]==f[i+1]||f[i]==f[i+1]||f[i]==e[i+1])
				ans=min(ans,d[i]+g[i]+h[i]);
		sum+=ans;
	}
	cout << sum;
	return 0;
}

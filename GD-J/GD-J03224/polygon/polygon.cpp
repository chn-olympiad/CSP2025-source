#include <bits/stdc++.h>
using namespace std;
int n,a[5005],maxx,pos1,pos2,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout << 1;
		else cout << 0; 
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		pos1=2;
		pos2=n*(n-1);
		for(int i=3;i<=n;i++)
		{
			pos1*=i;
			pos2*=n-i+1;
			ans+=pos2/pos1;
		}
		cout << ans;
	}
	return 0;
}

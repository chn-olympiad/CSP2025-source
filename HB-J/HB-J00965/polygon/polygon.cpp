#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5],n;
	cin >> n ;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int maxn=0,sum=0;
	for(int i=1;i<=3;i++)
	{
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(maxn*2<sum)
	    cout << 1;
	else
		cout << 0;
	return 0;
}

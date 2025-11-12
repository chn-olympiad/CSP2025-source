#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],maxx,dp[1000000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n ;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	return 0;
}

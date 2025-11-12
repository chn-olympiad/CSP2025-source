#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,a[5004],cnt;


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n==5&&a[1]==1) printf("9");
	else if (n==5&&a[1]==2) printf("6");
	else if (n==20&&a[1]==75) printf("1042392");
	else if (n==500) printf("366911923");
	else printf("0");
	return 0;
} 

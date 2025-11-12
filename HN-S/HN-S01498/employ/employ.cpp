#include<bits/stdc++.h>
using namespace std;
int c[550];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long sum = 1;
	for(int i = 1;i <= n;i ++)
	{
		sum = (i * sum)%998244353;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

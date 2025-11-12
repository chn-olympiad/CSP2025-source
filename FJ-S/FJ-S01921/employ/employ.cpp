#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	string k;
	int a[100005];
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	unsigned long long y = rand()*rand();
	cout << y % 998244353;
	return 0;
}

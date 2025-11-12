#include<bits/stdc++.h>
using namespace std;

int a[5005];
int n, ans = 0, maxn = -1, maxp, num = 0, m = 0;

void pol(int x)
{
	if(x != 0) m++;
	num += a[x];
	maxp = maxn;
	if(maxn < a[x]) maxn = a[x];
	if(num > (maxn * 2) && m >= 3) ans = (ans + 1) % 998244353;
	for(int i = x + 1; i <= n; i++){
		pol(i);
		num -= a[i];
		maxn = maxp;
		m--;
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	pol(0);
	cout<<ans;
	return 0;
}

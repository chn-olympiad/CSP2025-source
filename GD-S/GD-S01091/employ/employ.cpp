#include <bits/stdc++.h>
const int Mod = 998244353;
using namespace std;
int n,m;
string s;
int c[507];
long long ans = 1;
double total = 1;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i = n; i > n - m; i--)
	{
		total *= i;
		total /= (n - i + 1);
	}
	ans *= total;
	ans %= Mod;
	printf("%lld\n",ans);
}

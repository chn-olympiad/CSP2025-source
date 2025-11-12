#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
using namespace std;
const int N = 5e3+5, inf = 0x3f3f3f3f;
const ll mod = 998244353;
int n;
int a[N];
ll s[N], f[N];
ll ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d",&n) ;
	For(i, 1, n)
		scanf("%d",&a[i]);
	sort(a+1, a+1+n);
	For(i, 1, n)
		s[i] = s[i-1]+a[i];
//	For(i, 1, n)
//	{
//		if(s[i-1] > a[i])
//		{
//			a
//		}
//	}
	For(i, 3, n)
	{
		For(j, 2, i-1) For(z, 1, j-1)
		{
			if(a[i]-a[j] < a[z]) f[i] += f[z]*2+1;
			f[i] %= mod;
		}
		ans += f[i];
		ans %= mod;
		
	} 
	printf("%lld",ans);
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
using namespace std;
const int N = 5e5+5;
int n;
ll k;
ll a[N], s[N];
ll ans;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld",&n, &k);
	For(i, 1, n)
	{
		scanf("%lld",&a[i]);
		s[i] = s[i-1]^a[i];
	}
	For(l, 1, n) For(r, l, n)
	{
		ll tmp = s[r]^s[l-1];
		if(tmp == k) ans++;		
	}
	printf("%lld",ans);
	return 0;
}


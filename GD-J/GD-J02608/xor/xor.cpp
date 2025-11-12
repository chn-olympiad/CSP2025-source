#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;

ll n,k;
ll a[N],sum[N];
struct qu
{
	ll l,r;
}m[200*N];
ll now;
ll cnt,ans;

bool cmp(qu a,qu b)
{
	return a.r < b.r;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = a[i] ^ sum[i-1];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			ll x=0;
			if(i == j) x = a[i];
			else x = sum[j] ^ sum[i-1];
			if(x==k) m[++cnt].l = i,m[cnt].r = j;
		}
	}
	sort(m+1,m+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++)
	{
		if(m[i].l <= now)
			continue;
		ans++;
		now = m[i].r;
	}
	cout << ans;
	return 0;
}

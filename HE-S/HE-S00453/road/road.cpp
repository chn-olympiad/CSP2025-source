#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP ios_base::sync_with_stdio(0);cin.tie(0) 
#define MAXN 10001
using namespace std;
struct ab
{
	ll a, b, k;	
}a[1000001];
bool cmp(ab a, ab b)
{	
	return a.k < b.k;
}
ll n, m, k, ans, bs, i,j, book[101], f[MAXN], xc[11][MAXN], t = LLONG_MAX;
ll fd(ll x)
{
	if(f[x]!=x)
		f[x] = fd(f[x]);
	return f[x];
}
void add(ll a, ll b)
{
	f[fd(a)]=fd(b);
	return;
}
int main()
{
	I_AK_CSP;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	fr(1, n, i)
	{
		f[i] = i;
	}
	fr(1, m, i)
	{
		cin >> a[i].a >> a[i].b >> a[i].k;
	}
	fr(1,k,i)
	{
		cin >> book[i];
		ll h = book[i];
		fr(1, n,j)
		{
			cin >> xc[i][j];
			h+=xc[i][j];
		}
		t= min(t,h);
	}
	sort(a+1,a+m+1,cmp);
	fr(1,m,i)
	{
		ll x = fd(a[i].a),y=fd(a[i].b);
		if(x!= y)
		{
			ll mi = 1;
			fr(2,k,j)
			{
				if(book[j]+xc[j][a[i].a]+xc[j][a[i].b] < book[mi]+xc[mi][a[i].a]+xc[mi][a[i].b])
				{
					mi = j;
				}
			}
			if(book[mi]+xc[mi][a[i].a]+xc[mi][a[i].b] <= a[i].k)
			{
				ans += book[mi]+xc[mi][a[i].a]+xc[mi][a[i].b];
				book[mi] = 0;
			}
			else
			{
				ans += a[i].k;
			}
			add(x, y);
			bs++;
			if(bs == n - 1)
			{
				cout << min(ans,t);
				return 0;
			}
		}
	}
	return 0;
}

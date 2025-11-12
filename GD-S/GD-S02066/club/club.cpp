#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 100005;

struct node
{
	int a,b,c,id,se_mx,mxt,mx,val;
	bool operator<(const node &o)const
	{
		return val>o.val;
	}
}st[N];
int t,n,ans,an,bn,cn;
int cnt[4];
int& big(int &a, int &b, int &c)
{
	if(a<b)
	{
		if(b<c)
			return c;
		return b;
	}
	if(a<c)
		return c;
	return a;
}
int bigt(int &a, int &b, int &c)
{
	if(a<b)
	{
		if(b<c)
			return 3;
		return 2;
	}
	if(a<c)
		return 3;
	return 1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>st[i].a>>st[i].b>>st[i].c;
			st[i].id = i;
			st[i].mxt = bigt(st[i].a, st[i].b, st[i].c);
			st[i].mx = max({st[i].a, st[i].b, st[i].c});
			int &x = big(st[i].a, st[i].b, st[i].c);
			int y = x;
			x = -1e9;
			st[i].se_mx = max({st[i].a, st[i].b, st[i].c});
			x = y;
			st[i].val = st[i].mx-st[i].se_mx;
		}
		sort(st+1, st+n+1);
		cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1;i<=n;i++)
		{
			if(cnt[st[i].mxt] < n/2)
			{
				ans+=st[i].mx;
				cnt[st[i].mxt]++;
			}
			else
				ans+=st[i].se_mx;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

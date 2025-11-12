//60tps，可恶的贪心。。。 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll t, n, mem[N][4], id[N], ans;
ll fen[N], num[4], m1[N], m2[N], m3[N];
ll c1, c2, c3, cha, mid;
//fen[i] 第i个成员被分配的部门 
//num[i] 部门i中分到的人数
void work(ll men, ll cnt)//部门编号，总数 
{
	ll s[cnt+10];
	if(men == 1)
	{
		for(int i = 1; i <= cnt; ++i)
		{
			ll se = max(mem[m1[i]][2], mem[m1[i]][3]);
			s[i] = mem[m1[i]][1] - se;
		}
	}
	if(men == 2)
	{
		for(int i = 1; i <= cnt; ++i)
		{
			ll se = max(mem[m2[i]][1], mem[m2[i]][3]);
			s[i] = mem[m2[i]][2] - se;
		}
	}
	if(men == 3)
	{
		for(int i = 1; i <= cnt; ++i)
		{
			ll se = max(mem[m3[i]][2], mem[m3[i]][1]);
			s[i] = mem[m3[i]][3] - se;
		}
	}
	sort(s+1, s+cnt+1);
	for(int i = 1; i <= cha; ++i) ans -= s[i];
}
void solve()
{
	ans = 0;
	num[1] = num[2] = num[3] = 0;
	c1 = c2 = c3 = 0;
	cin >> n;
	mid = n/2;
	for(int i = 1; i <= n; ++i)
	{
		fen[i] = m1[i] = m2[i] = m3[i] = 0; 
		cin >> mem[i][1] >> mem[i][2] >> mem[i][3];
	}
	for(int i = 1; i <= n; ++i)
	{
		ll a = mem[i][1], b = mem[i][2], c = mem[i][3];
		ll maxi = max(a, max(b, c));
//		cout << maxi << '\n'; 
		if(maxi == a)
		{
			id[i] = 1;
			m1[++c1] = i;
		}
		if(maxi == b)
		{
			id[i] = 2;
			m2[++c2] = i;
		}
		if(maxi == c)
		{
			id[i] = 3;
			m3[++c3] = i;
		}
	}
//	cout << c1 << c2 << c3 << '\n';
	for(int i = 1; i <= c1; ++i) ans += mem[m1[i]][1];
	for(int i = 1; i <= c2; ++i) ans += mem[m2[i]][2];
	for(int i = 1; i <= c3; ++i) ans += mem[m3[i]][3];
	//计算ans，有超出再减掉 
	if(c1 > mid || c2 > mid || c3 > mid)//有超出 且一定只有一个部门会超出，且其他部门一定能放下 
	{
//		cout << c1 <<' ' << c2 << ' '<< c3 << '\n';
		ll mo, morid, maxc = max(c1, max(c2, c3));
		if(maxc == c1)
		{
			mo = c1;
			morid = 1; 
		}
		if(maxc == c2)
		{
			mo = c2;
			morid = 2;
		}
		if(maxc == c3) 
		{
			mo = c3;
			morid = 3;
		}
		cha = mo - mid;
//		cout << mo << ' ' << morid << '\n';
		work(morid, mo);
	}
	cout << ans << '\n';
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) solve();
	return 0;
}

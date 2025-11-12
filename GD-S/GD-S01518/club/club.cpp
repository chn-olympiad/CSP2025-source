#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
pair<long long, long long> d[N], e[N], f[N];
long long a[N], b[N], c[N], n, T, ans, na=1, nb=1, nc=1, num, na1=0, nb1=0, nc1=0;
bool flag[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		ans = 0;
		na = 1,nb = 1,nc = 1;
		na1 = 0,nb1 = 0,nc1 = 0;
		num = n;
		memset(flag, false, sizeof flag);
		for(long long i = 1; i <= n; i++)
		{
			cin >> d[i].first >> e[i].first >> f[i].first;
			a[i] = b[i] = c[i] = d[i].second = e[i].second = f[i].second = i;
		}
		for(long long i = 1; i < n; i++)
		{
			for(long long j = i + 1; j < n; j++)
			{
				if(d[a[i]].first <= d[a[j]].first)
					swap(a[i], a[j]);
				if(e[b[i]].first <= e[b[j]].first)
					swap(b[i], b[j]);
				if(f[c[i]].first <= f[c[j]].first)
					swap(c[i], c[j]);
			} 
		}
		while(num)
		{
			if(d[a[na]].first >= e[b[nb]].first && d[a[na]].first >= f[c[nc]].first && na1 < (n/2))
			{
				if((flag[d[a[na]].second] == false) && na1 < (n / 2)) 
				{	
					ans = ans + d[a[na++]].first;
					na1 += 1ll;
					num -= 1ll;
					flag[d[a[na]].second] = true;
				}
				else if(flag[d[a[na]].second])
				{
					++na;
				}
			}
			if(e[b[nb]].first >= d[a[na]].first && e[b[nb]].first >= f[c[nc]].first&& nb < (n/2))
			{
				if(flag[e[b[nb]].second ] == false && nb1 < (n/2))
				{
					ans += e[b[nb++]].first;
					nb1++;
					num--;
					flag[e[b[nb]].second] = true;
				}
				else if(flag[e[b[nb]].second])
				{
					nb++;
				}
			}
			if(f[c[nc]].first >= d[a[na]].first && f[c[nc]].first >= e[b[nb]].first&&nc<(n/2))
			{
				if(flag[f[c[nc]].second] == false && nc1 < (n/2)) 
				{
					ans += f[c[nc++]].first;
					++nc1;
					--num;
					flag[f[c[nc]].second] = true;
				}
				else if(flag[f[c[nc]].second])
				{
					nc++;
				}
			}
		}
	cout << ans;
 	}
	return 0;	
} 

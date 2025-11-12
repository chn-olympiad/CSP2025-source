#include <bits/stdc++.h>
using namespace std;
const int N = 500005 , M = 1024 * 1024 + 5;
int n , k , a , pre[N] , cnt , lastr , ans;
pair <int,int> t[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		pre[i] = pre[i - 1] ^ a;
	}
	for(int l = 1;l <= n;l++)
	{
		int rnum = pre[l - 1] ^ k;
		for(int r = l;r <= n;r++)
		{
			if(pre[r] == rnum)
			{
				t[++cnt].first = r;
				t[cnt].second = l;
				break;
			}
		}
	}
	sort(t+1,t+cnt+1);
	for(int i = 1;i <= cnt;i++)
	{
		int l = t[i].second , r = t[i].first;
		if(l > lastr)
		{
			ans++;
			lastr = r;
		}
	}
	cout << ans;
	return 0;
}

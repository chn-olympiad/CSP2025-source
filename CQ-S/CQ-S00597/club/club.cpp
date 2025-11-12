#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int t,n,a[N][3],ans,T[3][N],cnt[3],mx,o,ly;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n; cnt[0] = cnt[1] = cnt[2] = ans = 0;
		for(int i = 1;i <= n;i++) 
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2]; mx = max(a[i][0],max(a[i][1],a[i][2]));
			ans += mx;
			if(mx == a[i][0]) T[0][++cnt[0]] = max(a[i][1],a[i][2])-a[i][0];
			else if(mx == a[i][1]) T[1][++cnt[1]] = max(a[i][2],a[i][0])-a[i][1];
			else T[2][++cnt[2]] = max(a[i][1],a[i][0])-a[i][2];
		} mx = max(cnt[0],max(cnt[1],cnt[2]));
		if(mx <= n/2)
		{
			cout<<ans<<'\n';
			continue;
		}
		if(cnt[0] == mx) o = 0;
		else if(cnt[1] == mx) o = 1;
		else o = 2;
		sort(T[o]+1,T[o]+cnt[o]+1);
		while(mx > n/2)
		{
			ans += T[o][mx];//每次取最大的 
			mx--;
		}
		cout<<ans<<'\n'; 
	} 
	return 0;
}
/*
每一个人数<=n/2(n为偶数)
先让每个人去最大的
显然最多只有一个不满足
如果都满足答案就是这个
否则考虑平衡至这里只有n/2个人
显然的是这里为n/2，那边就是无限制的
贪心的选即可 
*/

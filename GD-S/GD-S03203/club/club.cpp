#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
	ll ret = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f) ,ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' ,ch = getchar();
	return ret * f;
}

int n;
const int N = 1e5 + 10;
int a[N][5];
priority_queue<int> q[5];

void solve()
{
	n = read();
	
	for (int i = 1;i <= 3;i++) while (!q[i].empty()) q[i].pop();
	
	for (int i = 1;i <= n;i++) for (int j = 1;j <= 3;j++) a[i][j] = read();
	
	ll ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int mx = a[i][1] ,id = 1 ,mx2 = 0;
		if (a[i][2] > mx) mx2 = max(mx2 ,mx) ,mx = a[i][2] ,id = 2;
		else mx2 = max(mx2 ,a[i][2]); 
		if (a[i][3] > mx) mx2 = max(mx2 ,mx) ,mx = a[i][3] ,id = 3;
		else mx2 = max(mx2 ,a[i][3]);
		
		ans += mx;
		q[id].push(mx2 - mx);
	}
	
	for (int i = 1;i <= 3;i++)
		while ((int)q[i].size() > n / 2)
			ans += q[i].top() ,q[i].pop();
	
	printf("%lld\n",ans);
}

int main()
{
	freopen("club.in" ,"r" ,stdin);
	freopen("club.out" ,"w" ,stdout);
	int T = read();
	
	while (T--) solve();
	
	return 0;
}
/*
*/

#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long int lli;
int t;
int n;
int a[100005][4],q[100005][4],query[100005],cnt[4]; // q:满意度排序下标记录（更期望的部门排序） query:损失排序下标记录 cnt:部门人数记录 
int ans;
bool cmp(int x,int y) // 按损失从大到小排
{
	return a[x][q[x][1]] - a[x][q[x][2]] > a[y][q[y][1]] - a[y][q[y][2]];
} 
void solve()
{
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;
	ans = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 3;j++)
		{
			cin >> a[i][j];
		}
		query[i] = i;
		if(a[i][1] >= a[i][2] && a[i][2] >= a[i][3]) // 1 > 2 > 3
		{
			q[i][1] = 1,q[i][2] = 2,q[i][3] = 3;
		}
		else if(a[i][1] >= a[i][3] && a[i][3] >= a[i][2]) // 1 > 3 > 2
		{
			q[i][1] = 1,q[i][2] = 3,q[i][3] = 2;
		}
		else if(a[i][2] >= a[i][1] && a[i][1] >= a[i][3]) // 2 > 1 > 3
		{
			q[i][1] = 2,q[i][2] = 1,q[i][3] = 3;
		}
		else if(a[i][2] >= a[i][3] && a[i][3] >= a[i][1]) // 2 > 3 > 1
		{
			q[i][1] = 2,q[i][2] = 3,q[i][3] = 1;
		}
		else if(a[i][3] >= a[i][1] && a[i][1] >= a[i][2]) // 3 > 1 > 2
		{
			q[i][1] = 3,q[i][2] = 1,q[i][3] = 2;
		}
		else if(a[i][3] >= a[i][2] && a[i][2] >= a[i][1]) // 3 > 2 > 1
		{
			q[i][1] = 3,q[i][2] = 2,q[i][3] = 1;
		}
//		cerr << q[i][1] << ' ' << q[i][2] << ' ' << q[i][3] << endl;
	}
	sort(query + 1,query + n + 1,cmp);
//	for(int i = 1;i <= n;i++)
//	{
//		cerr << query[i] << ' ';
//	}
//	cerr << endl;
	for(int i = 1,x = 0;i <= n;i++)
	{
		x = query[i];
		if(cnt[q[query[i]][1]] == n / 2) // 满员 
		{
			cnt[q[query[i]][2]]++;
			ans += a[x][q[x][2]];
		}
		else
		{
			cnt[q[query[i]][1]]++;
			ans += a[x][q[x][1]];
		}
	}
	cout << ans << endl;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
若一个部门有n/2人，则剩下两个部门至多只有n/2人，无论如何放均满足题意，
故若一个人最期望的部门满员了，则可以将其放置于第二期望的部门以尽量减小损失，
显然一定满足剩余两个部门人数均不多于n/2人
故可按损失排序，将损失（最期望的部门与第二期望的部门期望值之差）大的放至最期望的部门，剩下的如上放置 
*/
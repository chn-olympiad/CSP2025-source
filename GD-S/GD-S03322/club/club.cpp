#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

struct node
{
	int val, id;
	bool operator <(const node &A) const
	{
		return val<A.val;
	}
};
int G, n, a[N][5], cnt[5], ans=0;
priority_queue<node> q[5];
void add(int i, int op)
{
	if (op==1) ans+=a[i][1], cnt[1]++, q[1].push({max(-a[i][1]+a[i][2], -a[i][1]+a[i][3]), i});
	else if (op==2) ans+=a[i][2], cnt[2]++, q[2].push({max(-a[i][2]+a[i][1], -a[i][2]+a[i][3]), i});
	else ans+=a[i][3], cnt[3]++, q[3].push({max(-a[i][3]+a[i][1], -a[i][3]+a[i][2]), i});
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &G);
	while (G--)
	{
		ans=0;
		for (int i=1; i<=3; i++)
		{
			while (!q[i].empty()) q[i].pop();
			cnt[i]=0;
		}
		
		scanf("%d", &n);
		for (int i=1; i<=n; i++) scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			
		for (int i=1; i<=n; i++)
		{
			int mx=max(max(a[i][1], a[i][2]), a[i][3]);
			if (a[i][1]==mx)
			{
				if (cnt[1]<n/2) add(i, 1);
				else
				{
					if (a[i][1]+q[1].top().val>max(a[i][2], a[i][3])) ans+=a[i][1]+q[1].top().val, q[1].pop(), q[1].push({max(-a[i][1]+a[i][2], -a[i][1]+a[i][3]), i});
					else
					{
						if (a[i][2]>a[i][3]) add(i, 2);
						else add(i, 3);
					}
				}
			}
			else if (a[i][2]==mx)
			{
				if (cnt[2]<n/2) add(i, 2);
				else
				{
					if (a[i][2]+q[2].top().val>max(a[i][1], a[i][3])) ans+=a[i][2]+q[2].top().val, q[2].pop(), q[2].push({max(-a[i][2]+a[i][1], -a[i][2]+a[i][3]), i});
					else
					{
						if (a[i][1]>a[i][3]) add(i, 1);
						else add(i, 3);
					}
				}
			}
			else
			{
				if (cnt[3]<n/2) add(i, 3);
				else
				{
					if (a[i][3]+q[3].top().val>max(a[i][1], a[i][2])) ans+=a[i][3]+q[3].top().val, q[3].pop(), q[3].push({max(-a[i][3]+a[i][1], -a[i][3]+a[i][2]), i});
					else
					{
						if (a[i][1]>a[i][2]) add(i, 1);
						else add(i, 2);
					}
				}
			} 
			
//			printf("%d:%d\n", i, ans);
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0





<=3
 
2 [16] 7
4 [13] 3
[12] 7 5
[10] 7 5
[9] 4 3
[8] 2 3


-10+7+8
3
*/

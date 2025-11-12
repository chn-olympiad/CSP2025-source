#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int val,id;
};
node a[100005][3];
bool operator<(node a,node b)
{
	return a.val < b.val;
}
priority_queue<node> p[3];
bool cmp(node a,node b)
{
	return a.val > b.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		long long ans = 0;
		for(int i = 0; i < 3; i++)
		{
			while(p[i].size())
				p[i].pop();
		}
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 3; j++)
			{
				scanf("%d",&a[i][j].val);
				a[i][j].id = j;
			}
		for(int i = 1; i <= n; i++)
		{
			sort(a[i],a[i] + 3,cmp);
			p[a[i][0].id].push({-a[i][0].val + a[i][1].val,i});
			ans += a[i][0].val;
		}
		for(int i = 0; i < 3; i++)
		{
			while(p[i].size() > n / 2)
			{
				int id = p[i].top().id,val = p[i].top().val;
				p[a[id][1].id].push({a[id][1].val,i});
				ans += val;
				p[i].pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

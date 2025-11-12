#include <vector>
#include <cstdio>
using namespace std;
//不会做，考虑看测试点+暴力。
int n , k , ans = 0;
vector<int> v;
vector<bool> visit;
bool all_one = true;
void solve()
{
	int cur;bool vis = false;
	for (int len = 1;len <= n;len++)
	{
		for (int sta = 0;sta + len - 1 < n;sta++)
		{
			int en = sta + len - 1;
			vis=false;
			cur = v[sta];
			if (visit[sta])
				continue;
			for (int j = sta + 1;j <= en;j++)
			{
				if (visit[j])
				{
					vis=true;break;	
				}
				cur ^= v[j];
			}
			if (!vis and cur == k)
			{
				ans++;
				visit[sta]=true;
				for (int j = sta;j<sta+len-1;j++)
					visit[j]=true;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%d %d" , &n , &k);
	visit.resize(n + 5 , false);
	int tmp;
	for (int i = 0;i < n;i++)
	{
		scanf("%d" , &tmp);
		if (tmp != 1)
			all_one = false;
		v.push_back(tmp);
	}
	if (all_one and !k)
	{
		printf("%d\n" , n / 2);
	}
	else
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
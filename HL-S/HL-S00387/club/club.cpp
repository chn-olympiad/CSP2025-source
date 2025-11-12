#include <bits/stdc++.h>
using namespace std;

int t,n;

struct stu
{
	int x,y,z;
	int maxn;
	int scd;//第二大
	int t;//一大位置
	int t2;//二大位置
}a[10005];

bool cmp(stu a,stu b)
{
	return a.maxn > b.maxn;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int ans = 0;
	    int cnt[5]={};
		cin >> n;
		
		int temp = 0;
		temp = n/2;
		
		//输入&初始化数据 
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxn = max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].maxn  == a[i].x )//x
			{
				a[i].scd = max(a[i].y,a[i].z);
				a[i].t = 1;
				if(a[i].scd == a[i].y )//y
				{
					a[i].t2 = 2;
				}
				else//z
				{
					a[i].t2 = 3;
				}
			}
			else if(a[i].maxn == a[i].y)
			{
				a[i].scd = max(a[i].x,a[i].z);
				a[i].t = 2;
				if(a[i].scd == a[i].x )//x
				{
					a[i].t2 = 1;
				}
				else//z
				{
					a[i].t2 = 3;
				}
			}
			else if(a[i].maxn == a[i].z)
			{
				a[i].scd = max(a[i].x,a[i].y);
				a[i].t = 3;
				if(a[i].scd == a[i].x )//x
				{
					a[i].t2 = 1;
				}
				else//y
				{
					a[i].t2 = 2;
				}
			}
		}
		
		if(n == 2)
		{
			ans = max(a[1].maxn+a[2].scd,a[1].scd+a[2].maxn);
			cout << ans << endl;
			continue;
		}
		
		//处理 
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n;i++)
		{
			if(cnt[a[i].t] < temp)
			{
				ans += a[i].maxn;
				cnt[a[i].t]++;
			}
			else
			{
				ans += a[i].scd ;
				cnt[a[i].t2 ]++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


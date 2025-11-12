#include <bits/stdc++.h>
using namespace std;
int find_max(int a,int b,int c)
{
	return max(max(a,b),c);
}
int find_min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int find_mid(int a,int b,int c)
{
	return a + b + c - find_max(a,b,c) - find_min(a,b,c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int n;
	int la[100000+10],lb[100000+10],lc[100000+10];
	int p2p3_flag = 1;
	int p3_flag = 1;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++) 
		{
		cin >> la[i] >> lb[i] >> lc[i];
		int a = la[i];
		int b = lb[i];
		int c = lc[i];
		if (lb[i] != 0 || lc[i] != 0) p2p3_flag = 0;
		if (lc[i] != 0) p3_flag = 0;
		}
		int ans = 0;
		int flag = 2;
		if (p2p3_flag == 1)
		{
			sort(la+1,la+n+1);
			for (int i = n;i > n / 2;i--) ans += la[i];
			cout << ans << endl;
			continue;
		}
		if (p3_flag == 1)
		{
			int sab[100000+10];
			int vis_a[100000+10],vis_b[100000+10];
			int a_flag = 0;
			int b_flag = 0;
			for (int i = 1;i <= n;i++)
			{
				sab[i] = max(la[i],lb[i]) - min(la[i],lb[i]);
				ans += max(la[i],lb[i]);
				if (max(la[i],lb[i]) == la[i]) 
				{
					a_flag++;
					vis_a[i] = 1;
				}
					
				else if(max(la[i],lb[i]) == lb[i])
				{
					b_flag++;
					vis_b[i] = 1;
				}
				if (a_flag > n / 2)
				{
					int minn = 114514191;
					for (int j = 1;j <= i;j++)
					{
						if (vis_a[i] == 1 && max(la[i],lb[i]) == la[i]) minn = min(minn,sab[i]);
					}
					ans -= minn;
					a_flag--;
					b_flag++;
				}
				if (b_flag > n / 2)
				{
					int minn = 114514191;
					for (int j = 1;j <= i;j++)
					{
						if (vis_b[i] == 1 && max(la[i],lb[i]) == lb[i]) minn = min(minn,sab[i]);
					}
					ans -= minn;
					b_flag--;
					a_flag++;
				}
			}
			cout << ans << endl;
			continue;
		}
		if (n == 2)
		{
			int sab1,sab2;
			int a_f = 0,b_f = 0,c_f = 0;
			ans += find_max(la[1],lb[1],lc[1]);
			if (find_max(la[1],lb[1],lc[1]) == la[1]) a_f = 1;
			if (find_max(la[1],lb[1],lc[1]) == lb[1]) b_f = 1;
			if (find_max(la[1],lb[1],lc[1]) == lc[1]) c_f = 1;
			sab1 = find_max(la[1],lb[1],lc[1]) - find_mid(la[1],lb[1],lc[1]);
			sab2 = find_max(la[2],lb[2],lc[2]) - find_mid(la[2],lb[2],lc[2]);
			if (sab1 > sab2)
			{
				if (a_f) ans += max(lb[2],lc[2]);
				if (b_f) ans += max(la[2],lc[2]);
				if (c_f) ans += max(la[2],lb[2]);
			}
			else
			{
				ans -= find_max(la[1],lb[1],lc[1]);
				ans += find_mid(la[1],lb[1],lc[1]);
				if (find_mid(la[1],lb[1],lc[1]) == la[1]) ans += max(lb[2],lc[2]);
				if (find_mid(la[1],lb[1],lc[1]) == lb[1]) ans += max(la[2],lc[2]);
				if (find_mid(la[1],lb[1],lc[1]) == lc[1]) ans += max(la[2],lb[2]);
			}
			cout << ans << endl;
			continue;
		}
		for (int i = 1;i <= n;i++)
		{
			if (find_max(la[i],lb[i],lc[i]) == la[i]) ans += la[i];
			else if (find_max(la[i],lb[i],lc[i]) == lb[i]) ans += lb[i];
			else if (find_max(la[i],lb[i],lc[i]) == lc[i]) ans += lc[i];
		}
		cout << ans << endl;
	}
	return 0;
 } 

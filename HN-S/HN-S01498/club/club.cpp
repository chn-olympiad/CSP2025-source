#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int a[4];
	int o[4];
	int cha12,cha23;
}s[100005];
bool cmp(stu a,stu b)
{
	if(a.cha12 == b.cha12)
		return a.cha23 > b.cha23;
	else return a.cha12 > b.cha12;
}
int c[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,maxn,ans = 0;
	cin >> t;
	for(int i = 1;i <= t;i ++)
	{
		cin >> n;
		maxn = n / 2;
		for(int j = 1;j <= n;j ++)
		{
			
			int x,y,z;
			cin >> x >> y >> z;
			s[j].a[1] = x;
			s[j].a[2] = y;
			s[j].a[3] = z;
			if(x >= y && x >= z)
			{
				s[j].o[1] = 1;
				if(y >= z)
				{
					s[j].o[2] = 2;
					s[j].o[3] = 3;
					s[j].cha12 = x - y;
					s[j].cha23 = y - z;
				}
				else
				{
					s[j].o[2] = 3;
					s[j].o[3] = 2;
					s[j].cha12 = x - z;
					s[j].cha23 = z - y;
				}
			}
			else if(y >= x && y >= z)
			{
				s[j].o[1] = 2;
				if(x >= z)
				{
					s[j].o[2] = 1;
					s[j].o[3] = 3;
					s[j].cha12 = y - x;
					s[j].cha23 = x - z;
				}
				else
				{
					s[j].o[2] = 3;
					s[j].o[3] = 1;
					s[j].cha12 = y - z;
					s[j].cha23 = z - x;
				}
			}
			else if(z >= x && z >= y)
			{
				s[j].o[1] = 3;
				if(x >= y)
				{
					s[j].o[2] = 1;
					s[j].o[3] = 2;
					s[j].cha12 = z - x;
					s[j].cha23 = x - y;
				}
				else
				{
					s[j].o[2] = 2;
					s[j].o[3] = 1;
					s[j].cha12 = z - y;
					s[j].cha23 = y - x;
				}
			}
		}
		sort(s + 1,s + 1 + n,cmp);
		for(int j = 1;j <= 3;j ++)
			c[j] = 0;
		for(int j = 1;j <= n;j ++)
		{
				if(c[s[j].o[1]] < maxn)
				{
					c[s[j].o[1]] ++;
					ans += s[j].a[s[j].o[1]];
					continue;
				}
				if(c[s[j].o[2]] < maxn)
				{
					c[s[j].o[2]] ++;
					ans += s[j].a[s[j].o[2]];
					continue;
				}
				if(c[s[j].o[3]] < maxn)
				{
					c[s[j].o[3]] ++;
					ans += s[j].a[s[j].o[3]];
				}
		}
		cout << ans << endl;
		ans = 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t;
struct student
{
	int a[5];
	int maxpos,maxn;
};
bool cmp(student a, student b)
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
		student s[100005];
		int n, p[5] = {0,0,0,0,0},sum = 0;
		cin >> n;
		int mn = n / 2;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i].a[1] >> s[i].a[2] >> s[i].a[3];
			s[i].maxn = s[i].a[1];
			s[i].maxpos = 1;
			for(int j = 1; j <= 3; j++)
			{
				if(s[i].maxn <= s[i].a[2])
				{
					s[i].maxn = s[i].a[2];
					s[i].maxpos = 2;
				}
				if(s[i].maxn <= s[i].a[3])
				{
					s[i].maxn = s[i].a[3];
					s[i].maxpos = 3;
				}
			}
		}
		sort(s + 1, s + n + 1, cmp);
		for(int i = 1; i <= n; i++)
		{
			int compare = p[s[i].maxpos] + 1;
			if(mn >= compare)
			{
				p[s[i].maxpos]++;
				sum += s[i].maxn;
			}

		}
		cout << sum << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
struct student
{
	int a, b, c;
};
int getde(student x)
{
	int a = x.a, b = x.b, c = x.c;
	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);
	return a-b; 
}
bool cmp(student x, student y)
{
	int de1 = getde(x), de2 = getde(y);
	return (de1 < de2);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<student> s(n+5);
		for (int i=1;i<=n;i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			s[i] = student{a, b, c};
		}
		vector<student> tmp[5];
		int ans = 0;
		for (int i=1;i<=n;i++)
		{
			int a = s[i].a, b = s[i].b, c = s[i].c;
			ans += max(max(a, b), c);
			if (a > b && a > c)
				tmp[1].push_back(s[i]);
			else if (b > a && b > c)
				tmp[2].push_back(s[i]);
			else  
				tmp[3].push_back(s[i]);
		} 
		for (int i=1;i<=3;i++)
		{
			if (tmp[i].size() <= n/2)
				continue;
			sort(tmp[i].begin(), tmp[i].end(), cmp);
			for (int j=0;j<tmp[i].size()-n/2;j++)
			{
				ans -= getde(tmp[i][j]);
			} 
		}
		cout << ans << '\n';
	}
	return 0;
} 

//3
//4
//4 2 1
//3 2 4
//5 3 4 
//3 5 1
//4 
//0 1 0 
//0 1 0 
//0 2 0 
//0 2 0 
//2 
//10 9 8 
//4 0 0

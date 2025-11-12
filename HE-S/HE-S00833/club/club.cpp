#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int _;
int n;
bool vis[N];
bool tag_A = 1, tag_B = 1;

struct node
{
	int w, id;
	int cl;
}club_1[N], club_2[N], club_3[N];

bool cmp(node a, node b)
{
	if (a.w != b.w) return a.w > b.w;
	else return a.id < b.id;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> _;
	while (_--)
	{
		tag_A = tag_B = 1;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			vis[i] = 0;
			int a, b, c;
			cin >> a >> b >> c;
			if (b) tag_A = 0;
			if (c) tag_A = tag_B = 0;
			club_1[i].w = a, club_1[i].id = i;
			club_2[i].w = b, club_2[i].id = i;
			club_3[i].w = c, club_3[i].id = i;
		}
		sort(club_1 + 1, club_1 + n + 1, cmp);
		sort(club_2 + 1, club_2 + n + 1, cmp);
		sort(club_3 + 1, club_3 + n + 1, cmp);
		
		if (tag_A)
		{
			long long num = 0;
			for (int i = 1; i <= n / 2; ++i) num += club_1[i].w;
			cout << num << '\n';
			continue;
		}
		else
		{
			if (tag_B)
			{
				long long num = 0;
				int por1 = 0;
				int por2 = 0;
				for (int i = 1; i <= n; ++i)
				{
					if (club_1[i].id != club_2[i].id)
					{
						if (club_1[i].w > club_2[i].w && !vis[club_1[i].id] && por1 < n / 2) num += club_1[i].w, por1++;
						if (club_2[i].w < club_2[i].w && !vis[club_2[i].id] && por2 < n / 2) num += club_2[i].w, por2++;	
					} 
					else
					{
						int plk1 = club_1[i].w - club_1[i + 1].w;
						int plk2 = club_2[i].w - club_2[i + 1].w;
						if (plk1 > plk2 && !vis[club_1[i].id] && por1 < n / 2) num += club_1[i].w, por1++;
						if (plk1 < plk2 && !vis[club_2[i].id] && por2 < n / 2) num += club_2[i].w, por2++;	
					}
				}
				cout << num << '\n';
				continue;
			}
		}
		
	/*	int ans = 0;
		int pos[5] = {0};
		for (int i = 1; i <= n; ++i)
		{
			node a[5];
			a[1] = club_1[i];
			a[2] = club_2[i];
			a[3] = club_3[i];
			sort(a + 1, a + 3 + 1, cmp);
			for (int j = 1; j <= 3; ++j)
			{	
				if (!vis[a[j].id])
				{
										
					int brr = 0;
					if (a[j].id == club_1[i].id) brr = 1;
					if (a[j].id == club_2[i].id) brr = 2;
					if (a[j].id == club_3[i].id) brr = 3; 
					if (pos[brr] >= n / 2) continue;
					ans += a[j].w;
					vis[a[j].id] = 1;
					pos[brr]++;
				}
			}
		}
		cout << ans << '\n';*/
	}
	return 0;
}


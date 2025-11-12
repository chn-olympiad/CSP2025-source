#include <bits/stdc++.h>
using namespace std;

int n, t;
int a[100005][4], cnt[4];
vector <int> v[4];

struct fvrt //对于每位新社员 
{
	int id; //最喜欢部门的编号 
	int num; //对最喜欢部门的满意度 
};
fvrt m1[100005], m2[100005], m3[100005];


void find_p() //对于每位新社员，求其满意度最大、次大、最小的部门及具体满意度 
{
	for (int i = 1; i <= n; i++)
	{
		m1[i].num = max(max(a[i][1], a[i][2]), a[i][3]);
		if (m1[i].num == a[i][1])
			m1[i].id = 1;
		else if (m1[i].num == a[i][2])
			m1[i].id = 2;
		else
			m1[i].id = 3;
	}
	for (int i = 1; i <= n; i++)
	{
		m3[i].num = min(min(a[i][1], a[i][2]), a[i][3]);
		if (m3[i].num == a[i][1])
			m3[i].id = 1;
		else if (m3[i].num == a[i][2])
			m3[i].id = 2;
		else
			m3[i].id = 3;
	}
	for (int i = 1; i <= n; i++)
	{
		if ((m1[i].id == 1 && m3[i].id == 2) || (m3[i].id == 1 && m1[i].id == 2))
		{
			m2[i].id = 3;
			m2[i].num = a[i][3];
		}
		else if ((m1[i].id == 1 && m3[i].id == 3) || (m3[i].id == 1 && m1[i].id == 3))
		{
			m2[i].id = 2;
			m2[i].num = a[i][2];
		}
		else
		{
			m2[i].id = 1;
			m2[i].num = a[i][1];
		}
	}
}

bool cmp(fvrt x, fvrt y)
{
	return x.num > y.num;
}


bool cmp2(int x, int y)
{
	return x > y;
}
int main()
{
 	freopen("club.in", "r", stdin);
 	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(m1, 0, sizeof(m1));
		memset(m2, 0, sizeof(m2));
		memset(m3, 0, sizeof(m3));
		memset(cnt, 0, sizeof(cnt));
		bool f1 = 0, f2 = 0;
		cin >> n;
		int lim = n / 2;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				if (a[i][j] != 0 && (j == 2 || j == 3))
					f1 = 1;
			}
		if (f1 == 0)
		{
			vector <int> v1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= 3; j++)
					if (a[i][j] != 0)
						v1.push_back(a[i][j]);
			sort(v1.begin(), v1.end(), cmp2);
			int aa = 0;
			for (int i = 0; i < lim; i++)
				aa += v1[i];
			cout << aa << endl;
			continue;
		}
		find_p();
		sort(m1 + 1, m1 + n + 1, cmp);
		sort(m2 + 1, m2 + n + 1, cmp);
		sort(m3 + 1, m3 + n + 1, cmp);
		
		
		for (int i = 1; i <= n; i++)
		{
			if (cnt[m1[i].id] < lim)
			{
				cout << "sdfuf"<< endl;                             //==========================
				if (lim - cnt[m1[i].id] == 1)
				{
					for (int j = i; j <= n && j != i; j++)
					{
						if (m1[i].num + m2[j].num < m1[j].num + m2[i].num)
						{
							cout << 666 << endl;                             //==========================
							cout << m1[i].id << ' ' << m1[i].num << endl;
							cout << m2[j].id << ' ' << m2[j].num << endl;
							cout << m2[i].id << ' ' << m2[i].num << endl;
							cout << m1[j].id << ' ' << m1[j].num << endl;
							v[m2[i].id].push_back(m2[i].num);
							cnt[m2[i].id]++;
							v[m1[j].id].push_back(m1[j].num);
							cnt[m1[j].id]++;
						}
					}
					cout << 667 << endl;
					v[m1[i].id].push_back(m1[i].num);
					cnt[m1[i].id]++;
					cout << cnt[1] << ' ' << cnt[2]  << ' '<< cnt[3] << endl; 
					cout << m1[i].id << ' ' << m1[i].num << endl;                             //==========================
				}
				else			
				{
					cout << 12 << endl;                             //==========================
					v[m1[i].id].push_back(m1[i].num);
					cnt[m1[i].id]++;
					cout << cnt[1] << ' ' << cnt[2]  << ' '<< cnt[3] << endl; 
					cout << m1[i].id << ' ' << m1[i].num << endl;                             //==========================
				}
			}
			else if (cnt[m1[i].id] >= lim && cnt[m2[i].id] < lim)
			{
				cout << "sdfuf2"<< endl;                             //==========================
				v[m2[i].id].push_back(m2[i].num);
				cnt[m2[i].id]++;
			}
			else
			{
				cout << "sdfuf3"<< endl;                             //==========================
				v[m3[i].id].push_back(m3[i].num);
				cnt[m3[i].id]++;
			}
		}
		
		
		int ans = 0;
		for (int i = 1; i <= 3; i++)
			for (int j = 0; j < v[i].size(); j++)
				ans += v[i][j];
		cout << ans << endl;
	}
	return 0;
}


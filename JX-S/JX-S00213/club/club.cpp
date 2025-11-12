#include<bits/stdc++.h>
using namespace std;

struct rec1
{
	int id;
	int val;
	int d;
	rec1()
	{
		id = 0;
		val = 0;
		d = 0;
	}
	
	rec1(int idd, int vall, int dd)
	{
		id = idd;
		val = vall;
		d = dd;
	}
};
//from large to small
bool operator < (const rec1 &r1, const rec1 &r2)
{
	return r1.val < r2.val;
}

bool operator > (const rec1 &r1, const rec1 &r2)
{
	return r1.val > r2.val;
}

bool cmp(rec1 &r1, rec1 &r2)
{
	return r1 > r2;
}

int t = 0, n;
int a[100001][4];
int num[4];
int tot = 0;
rec1 rec1Array[100001];
rec1 recArray[100001];
long long ans = 0;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		tot = 0;
		num[1] = num[2] = num[3] = 0;
		ans = 0;
		//0 occupying
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			//int maxx = max(a[i][1], max(a[i][2], a[i][3]));
			int maxx = a[i][1];
			int ii = 1;
			if(a[i][2] > maxx)
			{
				maxx = a[i][2];
				ii = 2;
				
			}
			if(a[i][3] > maxx)
			{
				maxx = a[i][3];
				ii = 3;
			}
			
			rec1Array[++tot] = rec1(i, maxx, ii);
			ans += maxx;
		}
		//0 occupying
		sort(rec1Array + 1, rec1Array + n + 1, cmp);
		int choosed = 0;
		for(int i = 1; i <= n; i++)
		{
			//cout << rec1Array[i].d << " ";
			num[rec1Array[i].d]++;
			if(num[rec1Array[i].d] > n / 2) choosed = rec1Array[i].d;
		}
		if(choosed == 0)
		{
			cout << ans << endl;
			return 0;
		}
		
		tot = 0;
		for(int i = 1; i <= n; i++)
		{
			if(rec1Array[i].d == choosed)
			{
		
				rec1 r = rec1(i, 1000000, 0);
				
				for(int d = 1; d <= 3; d++)
				{
					if(d != choosed) r.val = min(a[rec1Array[i].id][choosed] - a[rec1Array[i].id][d], r.val);
				}
				recArray[++tot] = r;
			}
		}
		sort(recArray + 1, recArray + tot + 1, cmp);
		while(num[choosed] > n / 2)
		{
			num[choosed]--;
			ans -= recArray[tot].val;
			tot--;
		}
		cout << ans << endl;
		
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int ans, res, a[N][4], vis[N], n, cha[N], Cha[N];
int cnt1, cnt2, cnt3, Id[4][N], flag, id, cnt, Cnt;

int Max(int x, int y, int z)
{
	if(x >= y and x >= z) return 1;
	if(y >= x and y >= z) return 2;
	if(z >= x and z >= y) return 3;
}

int Min(int x, int y, int z)
{
	if(x <= y and x <= z) return 1;
	if(y <= x and y <= z) return 2;
	if(z <= x and z <= y) return 3;
}


int main()
{
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vis[1] = vis[2] = vis[3] = 0;
		res = ans = 0;
		cnt1 = cnt2 = cnt3 = Cnt = 0;
		memset(Id, 0, sizeof(Id));
		flag = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			
		for(int i = 1; i <= n; i++)
		{
			int maxid = Max(a[i][1], a[i][2], a[i][3]);
			int maxn = a[i][Max(a[i][1], a[i][2], a[i][3])];
			int minid = Min(a[i][1], a[i][2], a[i][3]);
			int minn = a[i][Min(a[i][1], a[i][2], a[i][3])];
			int sum = a[i][1] + a[i][2] + a[i][3];
			 
			ans += maxn;
			vis[maxid]++;
			if(maxid == 1)
				Id[1][++cnt1] = i;
			if(maxid == 2)
				Id[2][++cnt2] = i;
			if(maxid == 3)
				Id[3][++cnt3] = i;
				
//			cout << maxn << endl;
			
			if(vis[maxid] > n / 2)
			{
				flag = 1;
				id = maxid;
			}
			
			cha[i] = maxn + maxn + minn - sum;
			
			
		}
		
		if(flag == 0)
		{
			cout << ans << endl;
		}
		else
		{
//			cout << " jajffasdfas" << endl;
			if(id == 1) cnt = cnt1;
			if(id == 2) cnt = cnt2;
			if(id == 3) cnt = cnt3;
			
//			cout << id << ' ' << vis[id] << endl;
			
//			pre[id]
			for(int i = 1; i <= cnt; i++)
			{
				Cha[++Cnt] = cha[Id[id][i]];
//				cha[Id[id][i]] = 100000001;
				
			}
			sort(Cha + 1, Cha + Cnt + 1);
			
		
		
			for(int i = 1;i <= n; i++)
			{
				ans -= Cha[i];
				vis[id]--;
				if(vis[id] <= n / 2) break;
			}
			cout << ans << endl;
		
		}
		
	}
}

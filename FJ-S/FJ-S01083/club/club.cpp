#include<bits/stdc++.h>
using namespace std;

int t;
const int N = 1e5 + 5;
int a[4][N], box[4];
queue<int> q;
void dfs(int n)
{
	int ans;
	for(int i = 1; i <= n; i++)
	{
		int nn = n << 2;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0; 
		cin >> a[1][i] >> a[2][i] >> a[3][i]; 
		box[1] = a[1][i], box[2] = a[2][i], box[3] = a[3][i];
		sort(box + 1, box + 3 + 1);
		q.push();
		while(!q.empty())
		{
			if(box[1] = a[1][i] && cnt1 <= nn)
			{
				cnt1++;
				ans += a[1][i];
			}
			if(box[1] = a[2][i] && cnt2 <= nn)
			{
				cnt2++;
				ans += a[2][i];
			}
			if(box[1] = a[3][i] && cnt3 <= nn)
			{
				cnt3++;
				ans += a[3][i];
			}
		}	
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n, ans;
		cin >> n;
		club(n);
		cout << ans << endl;
	}
	return 0;
}

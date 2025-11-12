#include<bits/stdc++.h>
using namespace std;

int T, n;
int a[100005][5];
int cnt;
int x[100005], y[100005], z[100005];
int b2[5];
int b[5];
int ans1, ans2, ans3;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	
	while(T--)
	{
		cin >> n;
		cnt = n / 2;
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		for(int i = 1; i <= 3; i++) b[i] = 0;
		 for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				cin >> a[i][j];
				
		for(int i = 1; i <= n; i++)
		{
			x[i] = a[i][1];
			y[i] = a[i][2];
			z[i] = a[i][3];
		}
		sort(x + 1, x + n + 1);
		sort(y + 1, y + n + 1);
		sort(z + 1, z + n + 1);
		for(int i = 0; i < cnt; i++)
		{
			b[1] += x[n - i];
			b[2] += y[n - i];
			b[3] += z[n - i];
		}
		b2[1] = b[1];
		b2[2] = b[2];
		b2[3] = b[3];
		sort(b + 1, b + 3 + 1);
		
		if(b[3] == b2[1]) 
			ans1 = b[3] + y[n] + z[n];
		if(b[3] == b2[2])
			ans2 = b[3] + x[n] + z[n];
		if(b[3] == b2[3])
			ans3 = b[3] + x[n] + y[n];
		cout << max(max(ans1, ans2), ans3);
	}
	
	return 0;
}

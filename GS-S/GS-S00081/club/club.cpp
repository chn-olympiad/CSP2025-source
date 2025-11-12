#include<bits/stdc++.h>
using namespace std;

int a[100005][4];
int t, n, m;
int ans=0;

void dft(int x, int y, int z, int step, int anss)
{
	if(step==n) 
	{
		ans=max(ans, anss);
		return;
	}
	if(x+1<=m) dft(x+1, y, z, step+1, anss+a[step+1][1]);
	if(y+1<=m) dft(x, y+1, z, step+1, anss+a[step+1][2]);
	if(z+1<=m) dft(x, y, z+1, step+1, anss+a[step+1][3]);
	
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		ans=0;
		cin >> n;
		m=n/2;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dft(0,0,0,0,0);
		cout << ans << endl;
	}
	return 0;
}



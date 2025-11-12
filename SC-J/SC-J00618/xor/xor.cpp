#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
const int inf = -1e17;
int a[N];
int xors[N];
int latepos[N][300];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		xors[i] = xors[i-1] ^ a[i];
	}
	//xor[l~r] = xors[r]^xor[l-1]
	for(int i = 0;i < 256;i++)
	{
		latepos[0][i] = inf;
	}
	for(int j = 0;j < 256;j++)
	{
		for(int i = 1;i <= n;i++)
		{
			if(xors[i-1] == j) latepos[i][j] = i-1;
			else latepos[i][j] = latepos[i-1][j];
		}
	}
	int cnt = 0;
	int l = -1;
	for(int r = 1;r <= n;r++)
	{
		if(latepos[r][k^xors[r]] == inf) continue;
		if(latepos[r][k^xors[r]] >= l)
		{
			cnt++;
			l = r;
			continue;
		}
	}
	cout << cnt;
	return 0;
}
/*
1048576
*/
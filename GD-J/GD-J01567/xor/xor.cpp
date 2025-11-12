#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;

int a[N];
bool a01[N][25];
int s[N][25];

void mset()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= 21; j++)
			a01[i][j] = 0; 
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= 21; j++)
			s[i][j] = 0;
}

void get01(int p)
{
	int x = a[p], cnt = 0;
	while(x != 0)
	{
		a01[p][++cnt] = x % 2;
		x /= 2;
	}
}

bool comp(int l, int r)
{
	for(int i = 1; i <= 20; i++)
		if((s[r][i] - s[l - 1][i]) % 2 != a01[0][i]) return 0;
	return 1;
}

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, cnt0 = 0, cnt1 = 0, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 0) cnt0++;
		if(a[i] == 1) cnt1++;
	}
	
	if(k == 0)
		cout << cnt0 + cnt1 / 2;
	
	else if(k == 1)
		cout << cnt1;
	
	else
	{
		mset();
		a[0] = k;
		for(int i = 0; i <= n; i++)
			get01(i);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 20; j++)
				s[i][j] = s[i - 1][j] + a01[i][j];
				
		int last = 0;
		for(int r = 1; r <= n; r++)
		{
			for(int l = last + 1; l <= r; l++)
			{
				if(comp(l, r))
				{
					ans++;
					last = r;
					break;
				}
			}
		}
		cout << ans;
	}

	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool s[500005][25];
int v[1 << 20];
bool f[500005];
int cur = 0;
pair<int,int> b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int j = 0;j < 20;j++)
	{
		for(int i = 1;i <= n;i++)
		{
			s[i][j] ^= (a[i] & (1 << j));
		}
	}
	for(int j = 0;j < 20;j++)
	{
		for(int i = 1;i <= n;i++)
		{
			s[i][j] ^= s[i - 1][j];
		}
	}
	memset(v,-1,sizeof(v));
	v[0] = 0;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int sum1 = 0,sum2 = 0;
		for(int j = 0;j < 20;j++)
		{
			sum2 += (1 << j) * s[i][j];
			//cout << (k & (1 << j)) << endl;
			if((k & (1 << j)) > 0)
			{
				sum1 += (1 << j) * (s[i][j] ^ 1);
			}
			else
			{
				sum1 += (1 << j) * s[i][j];
			}
		}
		//cout << sum1 << endl;
		if(v[sum1] == -1)
		{
			v[sum2] = i;
		}
		else
		{
			int l = v[sum1] + 1;
			cur++;
			b[cur] = make_pair(i,l);
			v[sum1] = -1;
			v[sum2] = i;
		}
	}
	sort(b + 1,b + cur + 1);
	int now = 0;
	for(int i = 1;i <= cur;i++)
	{
		if(b[i].second > now)
		{
			ans++;
			now = b[i].first;
			//cout << b[i].second << " " << b[i].first << endl;
		}
	}
	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, k, xor1[N][N], xor2[N][3], num, used[N], a[N], many;

void dfs(int j, int sum)
{
	if(j == many + 1)
	{
		num = max(num, sum);
		return;
	}
	
	bool fl = false;
	
	dfs(j + 1, sum);
	
	for(int i = xor2[j][1];i <= xor2[j][2];i ++)
	{
		if(used[i] == 1) fl = true;
	}
	
	if(!fl)
	{
		for(int i = xor2[j][1];i <= xor2[j][2];i ++)
		{
			used[i] = 1;
		}
		dfs(j + 1, sum + 1);
		for(int i = xor2[j][1];i <= xor2[j][2];i ++)
		{
			used[i] = 0;
		}
	} 
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			xor1[i][j] = xor1[i][j - 1] ^ a[j];
		}
	}
	
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			if(xor1[i][j] == k) 
			{
				xor2[++ many][1] = i;
				xor2[many][2] = j;
			}
		}
	}
	
	dfs(1, 0);
	
	cout << num << endl;

	fclose(stdin), fclose(stdout);
	
	return 0;
}


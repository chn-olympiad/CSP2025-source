#include <bits/stdc++.h>
using namespace std;

int a[5005];
int w[5005];
bool f[5005];

int flag;
int k = 998244353;
int cnt = 0;
int n;
void dfs(int step , int last)
{
	if(step > flag)
	{
		int sum = 0;
		int maxn = 0;
		for(int i = 1; i < step; i++)
		{
			sum += w[i];
			maxn = max(maxn , w[i]);
		}
		if(sum > maxn * 2)
		{
			cnt++;
			cnt = cnt % k;
			for(int i = 1; i < step; i++)
			{
				cout << w[i] << " ";
			}
			cout << endl;
		}
		return ;
	}
	for(int i = last + 1; i <= n; i++)
	{
		if(f[i] == 0)
		{
			f[i] = 1;
			w[step] = a[i];
			dfs(step + 1 , i);
			f[i] = 0;
		}
	}
}

int main()
{
	freopen(polygon.in , "r" , stdin);
	freopen(polygon.out , "w" , stdout); 
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 3; i <= n; i++)
	{
		flag = i;
		dfs(1 , 0);
	}
	cout << cnt;
	return 0;
 } 

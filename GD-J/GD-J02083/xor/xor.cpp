#include <bits/stdc++.h>
using namespace std;
const int N= 5e5 + 10;
int n,k;
int a[N];
bool vis[N];
void dfs()
{
	int sum = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] == k) 
		{
			vis[i] = 1;
			sum ++;
			continue;
		}
	}
	for(int i = 1; i <= n - 1; i ++)
	{
		if(vis[i]) continue;
		int temp = a[i];
		for(int j = i + 1; j <= n; j ++)
		{
			if(vis[j] == 1) break;
			temp = temp ^ a[j];
			if(temp == k)
			{
				sum++;
				break;
			}
		}
	}
	cout << sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	dfs();
	return 0;
}

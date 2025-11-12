#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
int a[N], jump[N];
bool vis[N];
/*
int dfs(int x)
{
	if(!vis[jump[x]]) return jump[x];
	return jump[x] = dfs(x + 1);
}*/

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == k)
		{
			ans++;
			vis[i] = true;
			//printf("%d %d\n", i, i);
		}
		jump[i] = i + 1;
	}
	/*int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == true) sum++;
	}
	printf("%d\n", sum);*/
	for(int siz = 2; siz <= n; siz++)
	{
		int st = a[1], xo = 0;
		bool flag = false;
		int all = n - siz + 1;
		for(int i = 1; i <= all; i++)
		{
			if(!flag)
			{
				bool f = false;
				xo = 0;
				if(i + siz - 1 > n) break;
				for(int j = i; j <= i + siz - 1; j++)
				{
					if(vis[j])
					{
						//printf("Wrong %d %d\n", i, i + siz - 1);
						i = j;//i = dfs(j);
						f = true;
						break;
					}
					xo ^= a[j];
				}
				if(f)
				{
					//printf("Wrong2 %d %d\n", i, i + siz - 1);
					continue;
				}
				if(xo == k)
				{
					ans++;
					//printf("%d %d\n", i, i + siz - 1);
					for(int j = i; j <= i + siz - 1; j++) vis[i] = true;
				}
				//else printf("Rem %d\n", xo);
				st = a[i];
				flag = true;
				//printf("Wrong3 %d %d\n", i, i + siz - 1);
				continue;
			}
			int num = i + siz - 1;
			if(vis[num])
			{
				i = num;//i = dfs(num);
				flag = false;
				continue;
			}
			xo ^= st;
			xo ^= a[num];
			st = a[i];
			if(xo == k)
			{
				ans++;
				//printf("%d %d\n", i, num);
				for(int j = i; j <= num; j++) vis[i] = true;
			}
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
*/

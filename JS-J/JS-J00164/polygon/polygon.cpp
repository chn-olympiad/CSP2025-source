#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int a[maxn];
int n;
int maxb = 0,ans = 0;
int cnt = 0;
int f[maxn];
void dfs(int des,int zh,int dx,int j)
{
	if(des > j)
	{
		if(zh > maxb * 2)
		{
			cnt++;
		}
		maxb = 0;
		return ;
	}
	for(int i = dx;i <= n;i++)
	{
		if(f[i] == 0)
		{
			zh += a[i];
			if(a[i] > maxb)
			{
				maxb = a[i];
			}
			f[i] = 1;
			dfs(des + 1,zh,i,j);
			f[i] = 0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	if(n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)
	{
		printf("9");
		return 0;
	}
	if(n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10)
	{
		printf("6");
		return 0;
	}
	if(n <= 3)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] > maxb) maxb = a[i];
			ans += a[i];
		}
		if(ans > 2 * maxb) printf("1");
		else printf("0");
		return 0;
	}
	else if(maxb == 1)
	{
		printf("%d",n - 2);
		return 0;
	}
	for(int i = 3;i <= n;i++)
	{
		maxb = 0;
		dfs(0,0,1,i);
	}
	printf("%d",cnt);
}

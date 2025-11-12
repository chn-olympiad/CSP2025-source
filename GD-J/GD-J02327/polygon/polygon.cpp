#include <bits/stdc++.h>
using namespace std;
int n,a[50000],sam = 0;
int findmax(int x,int y)
{
	int maxn = a[x];
	for (int i = x+1;i <= y;i++)
		if (maxn < a[x])
			maxn = a[x];
	return maxn;
}
int findnum(int x,int y)
{
	int maxn = 0;
	for (int i = x;i <= y;i++)
		maxn += a[i];
	return maxn;
}
void dfs(int x,int num,int sum,int maxn)//numºÏ sumÊý 
{
	if (sum < 3 && x == n-1)
		return ;
	else if (sum < 3)
	{
		dfs(x+1,num+a[x],sum+1,max(maxn,a[x]));
		dfs(x+1,num,sum,maxn);
	}
	else if (sum >= 3 && x != n-1)
	{
		if (num > maxn*2)
			sam++;
		dfs(x+1,num+a[x],sum+1,max(maxn,a[x]));
		dfs(x+1,num,sum,maxn);
	}
	else if (sum >= 3 && x == n-1)
	{
		if (num > maxn*2)
			sam++;
		return ;
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	if (n < 3)
	{
		cout <<"0";
	}
	else if (n == 3)
	{
		if (findmax(0,2) * 2 < findnum(0,2))
			cout << "1";
		else
			cout << "0";
	}
	else
	{
		dfs(0,0,0,-1);
		cout << sam;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

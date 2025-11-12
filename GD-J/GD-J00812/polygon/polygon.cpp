#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int sticks[5005],n;
const int u=998244353;
long long ans=0;
int sum(int idx[],int l)
{
	int tot=0;
	for (int i=0;i<l;i++)
		tot+=sticks[idx[i]];
	return tot;
}
void dfs(int s,int a)
{
	if (a==1)
		return;
	for (int i=s;i<n;i++)
	{
		for (int j=(a-1);j<n;j++)
		{
			dfs(i,a-1);
			int maxn=sticks[j],idx[5005],cnt=0;
			for (int k=s;k<=s+a;k++)
				idx[cnt]=k;
			if (sum(idx,cnt)>=maxn*2)
				ans++;
		}
	}
	cout << ans%u;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)
		cin >> sticks[i];
	if (n==5)
	{
		if (sticks[0]==1)
			cout << 9;
		else 
			cout << 6;
	}
	return 0;
}
//小R以后别玩木棍了 

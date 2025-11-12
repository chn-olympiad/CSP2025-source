#include<bits/stdc++.h>
using namespace std;
int a[505], times[505];
bool vis[505];
int n, m;
long long sum=0;
int ans=0, cnt=0;
void DFS(int step)
{
	if(step>n)
	{
		if(ans>=m)
		{
			sum++;
			sum%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			int flag1=0, flag2=0;
			if(cnt<times[i])
			{
				if(a[step]==1)
				{
					flag1=1;
					ans++;
				}
				else
				{
					flag2=1;
					cnt++;
				}
			}
			DFS(step+1);
			ans-=flag1;
			cnt-=flag2;
			vis[i]=false;
		}
	}
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
		char c;
		cin >> c;
		a[i]=(c-'0');
	}
	for(int i=1;i<=n;i++)
	{
		cin >> times[i];
	}
    DFS(1);
    cout << sum;
    return 0;
}
/*
1
4
1 0 0
1 0 0
2 0 0
2 0 0
*/

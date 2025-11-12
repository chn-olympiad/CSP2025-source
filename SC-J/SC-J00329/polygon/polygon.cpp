#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long ans;
int n;

void dfs(int now,int lst,int sum)
{
	if(now == n + 1) 
	{
		if(a[lst] * 2 < sum)
		{
			ans ++;
			ans %= 998244353;
		}
		return ;
	}
	dfs(now+1,now,sum+a[now]);
	dfs(now+1,lst,sum);
	
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	dfs(1,0,0);
	
	cout<<ans;
	
	return 0;
}
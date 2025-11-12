#include<bits/stdc++.h>
using namespace std;
int t;
int v[5];
long long ans;

struct node
{
	int g[4];
}a[100010];

void dfs(int n,int num,long long s)
{
	if(v[1] == 0 || v[2] == 0 || v[3] == 0)	return;
	
	if(num == n)
	{
		ans = max(ans,s);
		return;
	}
	for(int i = 1; i <= 3; i++)
	{
		v[i]--;
		dfs(n,num+1,s+a[num+1].g[i]);
		v[i]++;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].g[1] >> a[i].g[2] >> a[i].g[3];
		}
		v[1] = n/2+1,v[2] = n/2+1,v[3] = n/2+1;
		dfs(n,0,0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}

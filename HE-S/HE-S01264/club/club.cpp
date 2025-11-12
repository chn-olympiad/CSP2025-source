#include<bits/stdc++.h>
using namespace std;
int a[510000], b[510000], c[510000];
int n, t, sum1, sum2;
int tot;
long long ans = -1;
void dfs(int aa,int bb,int cc,long long ss,int i)
{
	if(i == n+1)
	{
		ans = max(ans,ss);
		return;
	}
	if(aa < tot)
	{
		dfs(aa+1,bb,cc,ss+a[i],i+1);
	}
	if(bb < tot)
	{
		dfs(aa,bb+1,cc,ss+b[i],i+1);
	}
	if(cc < tot)
	{
		dfs(aa,bb,cc+1,ss+c[i],i+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		tot = n/2;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] == 0) sum1++;
			if(c[i] == 0) sum2++;
		}
		if(sum1 == n&&sum2 == n)
		{
			sort(a+1,a+n+1);
			for(int i=1;i<=n/2;i++) ans += a[i];
			cout << ans << "\n";
			ans = -1;
			sum1 = sum2 = 0; 
		}
		else
		{
			dfs(0,0,0,0,1);
			cout << ans << "\n";
			ans = -1;
		}
		
	}
	return 0;
} 

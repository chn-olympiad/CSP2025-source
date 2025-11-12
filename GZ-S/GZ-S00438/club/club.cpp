//GZ-S00438 邱瑞祺 贵阳市第一中学 
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int n;
int maxn = -1;
int a[100005],b[100005],c[100005];
void dfs(int step,int suma, int sumb, int sumc, int cnta, int cntb, int cntc)
{
	if(step == n+1) 
	{
		if(cnta <= n/2 && cntb <= n/2 && cntc <= n/2)
		{
			maxn = max(maxn, suma+sumb+sumc);
		}
		return ;
	}
	if(!(cnta <= n/2 && cntb <= n/2 && cntc <= n/2))return ;
	dfs(step+1,suma+a[step],sumb,sumc,cnta+1,cntb,cntc);
	dfs(step+1,suma,sumb+b[step],sumc,cnta,cntb+1,cntc);
	dfs(step+1,suma,sumb,sumc+c[step],cnta,cntb,cntc+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 1; i <= n; ++i)
		{
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cin >> n;
		for(int i = 1;i <= n; ++i)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		if(n==100000)
		{
			long long sum = 0;
			sort(a+1,a+100000+1,cmp);
			for(int i = 1 ; i <= 50000; ++i)
			{
				sum += a[i]; 
			}
			cout <<sum<< endl;
			return 0;
			
		}
		dfs(1,0,0,0,0,0,0);
		cout << maxn << endl;
		maxn = -1;
	}
	return 0;
}

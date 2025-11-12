#include<iostream>
#define ll long long
using namespace std;
struct dot
{
	ll a[4];	
}p[10005];
ll sign[4],n,max1 = 0,ans[20001];
void dg(ll m,ll ans)
{
	ll i;
	for(i = 1;i <= 3;i++)
	{
		if(sign[i] < n/2)
		{
			ans+=p[m].a[i];
			sign[i]++;
			if(m == n)
			{
				if(ans > max1)
					max1 = ans;
			}
			dg(m+1,ans);
			ans-=p[m].a[i];
			sign[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a,i,j,k,l,flag = 0;
	cin >> a;
	for(i = 1;i <= a;i++)
	{
		max1 = 0;
		cin >> n;
		for(j = 1;j <= n;j++)
		{
			cin >> p[j].a[1] >> p[j].a[2] >> p[j].a[3];
			if(p[j].a[2] != 0) flag = 1;
		}
		for(j = 0;j <= n/2;j++) ans[j] = 0;
		if(flag == 0)
		{
			for(j = 1;j <= n;j++)
			{
				for(k = n/2;k >= 1;k--)
				{
					ans[k] = max(ans[k],ans[k-1] + p[j].a[1]);
				}
			}
			cout << ans[n/2] << endl;
		}
		else
		{
			dg(1,0);
			cout << max1 << endl;
		}
	}
	return 0;
}

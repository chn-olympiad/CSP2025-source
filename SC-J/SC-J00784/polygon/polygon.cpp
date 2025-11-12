#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10 , p=998244353;

ll n,a[N],cnt,ans;
bool vis[N];

void dfs(ll dep)
{
	if(dep > n)
	{
		if(cnt<3) return ;
		ll x=0,y=-1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
//				cout << i << ",";
				x+=a[i];
				y=max(y,a[i]);
			}
		}
		if(x > 2*y)
		{
//			cout << "--------";
			ans++;
			ans%=p;
		}
//		cout << "\n";
		return ;
	}
	vis[dep]=1;
	cnt++;
	dfs(dep+1);
	vis[dep]=0;
	cnt--;
	dfs(dep+1);
	return ;
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
	dfs(1);
	cout << ans << endl;
	return 0;
}
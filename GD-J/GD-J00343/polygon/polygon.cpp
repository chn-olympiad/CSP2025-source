#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
int a[N];

int ans=0;
int ma;
bool check(int z,int m)
{
	if(z/2<m) return false;
	return true;
}

void dfs(int now,int z,int m)
{
	if(now==n)
	{
		if(check(z,m))
		{
			ans++;
			ans%=998244353;
			return ;
		}
	}
	
	dfs(now+1,z,m);
	int u=m;
	if(m<a[now])
	{
		m=a[now];
	}
	
	z+=a[now];
	dfs(now+1,z,m);
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	dfs(1,0,INT_MIN);
	
	cout<<ans<<endl;
	return 0;
}

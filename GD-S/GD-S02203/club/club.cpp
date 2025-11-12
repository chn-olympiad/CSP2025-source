#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
struct Node
{
	int x,y,z;
}a[N];
int f[207][207][207];
inline bool cmp(Node A,Node B)
{
	return A.x>B.x;
}
void solve()
{
	memset(f,0,sizeof(f));
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	if(n>200)
	{
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
			ans+=max({a[i].x,a[i].y,a[i].z});
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			for(int t=0;t<=i-1-j;t++)
			{
				f[i][j][t]=max(f[i][j][t],f[i-1][j][t]+a[i].z);
				f[i][j+1][t]=max(f[i][j+1][t],f[i-1][j][t]+a[i].x);
				f[i][j][t+1]=max(f[i][j][t+1],f[i-1][j][t]+a[i].y);
			}
		}
	}
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			if(i+j>=n/2)
			{
				if(f[n][i][j]>ans)
				{
					ans=f[n][i][j];
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}

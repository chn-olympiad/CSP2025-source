#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,a[500005][3];
int ans;
void dfs(int now,int x,int y,int z,int cc)
{
	if(now==n+1) ans=max(ans,cc);
	
	if(x+1<=n/2) dfs(now+1,x+1,y,z,cc+a[now][1]);
	if(y+1<=n/2) dfs(now+1,x,y+1,z,cc+a[now][2]);
	if(z+1<=n/2) dfs(now+1,x,y,z+1,cc+a[now][3]);
}
bool check()
{
	for(int i=1;i<=n;i++)
	  if(a[i][2] || a[i][3])
	    return false;
	return true;
}
int b[500005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		
		if(check())
		{
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			  ans+=b[i];
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}


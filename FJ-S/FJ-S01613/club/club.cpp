#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,v[4],a[10010][4],ans,bo1,bo2;
ll b[10010];
bool cmp(ll x,ll y)
{
	return x>y;
}
void search(ll x,ll ans1)
{
	ans=max(ans,ans1);
	if(x!=n+1)
	{
		for(int i=1;i<=3;i++)
		{
			if(v[i]<(n/2))
			{
				v[i]++;
				search(x+1,ans1+a[x][i]);
				v[i]--;
			}
		}
		return ;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(v,0,sizeof(v));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]&&j==2) bo1=1;
				if(a[i][j]&&j==3) bo2=1;
			}
		}
		if(bo1!=0&&bo2!=0)
		{
			search(1,0);
		    cout<<ans<<"\n";
		}
		else if(bo1==0&&bo2==0)
		{
			for(int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=b[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
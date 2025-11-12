#include<bits/stdc++.h>
using namespace std;
int n,t,c[5],ans;
pair<pair<int,int>,pair<int,int>>a[100005];
void dfs(int x,int s)
{
//	cout<<x<<endl;
	if(x==n+1)
	{
		ans=max(ans,s);
		return;
	}
	int b[5];
	b[1]=a[x].first.second,b[2]=a[x].second.first,b[3]=a[x].second.second;
	for(int i=1;i<=3;i++)
	{
		if(c[i]<n/2)
		{
//			cout<<x<<':'<<i<<endl;
			c[i]++;
			dfs(x+1,s+b[i]);
			c[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;ans=0;
		for(int i=1;i<=3;i++)
		{
			c[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			
			int b1,b2,b3;
			cin>>b1>>b2>>b3;
			a[i]={{max(max(b1,b2),b3),b1},{b2,b3}};
		}
//		sort(a+1,a+n+1,greater<pair<pair<int,int>,pair<int,int>>>());
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}


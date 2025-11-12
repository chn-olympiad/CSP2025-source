#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,pos,res;
};
bool cmp(node x,node y)
{
	return x.res<y.res;
}
void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> a(n,vector<int>(3));
	vector<vector<node>> sum(3);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int now=0,pos=-1;
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>now) pos=j,now=a[i][j];
		}
		ans+=now;
		int resx=INT_MAX,posx=-1;
		for(int j=0;j<3;j++)
		{
			if(j!=pos)
			{
				if(resx>now-a[i][j]) resx=now-a[i][j],posx=j; 
			}
		}
		sum[pos].push_back({i,posx,resx});
	}
	for(int i=0;i<3;i++) sort(sum[i].begin(),sum[i].end(),cmp);
	for(int i=0;i<3;i++)
	{
		if(sum[i].size()>n/2)
		{
			int need=sum[i].size()-n/2;
			for(auto p:sum[i])
			{
				if(need==0) break;
				need--;
				ans-=p.res;
			}
			break;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}

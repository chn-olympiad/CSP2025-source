#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[200010][4];
vector<int> ve[4];
bool cmp1(int x,int y)
{
	int mnx=min(a[x][1]-a[x][2],a[x][1]-a[x][3]);
	int mny=min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
	if(mnx<mny)
		return 1;
	else
		return 0;
}
bool cmp2(int x,int y)
{
	int mnx=min(a[x][2]-a[x][1],a[x][2]-a[x][3]);
	int mny=min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
	if(mnx<mny)
		return 1;
	else
		return 0;
}
bool cmp3(int x,int y)
{
	int mnx=min(a[x][3]-a[x][2],a[x][3]-a[x][1]);
	int mny=min(a[y][3]-a[y][2],a[y][3]-a[y][1]);
	if(mnx<mny)
		return 1;
	else
		return 0;
}
void solve()
{
	int ans=0;
	cin>>n;
	ve[1].clear();
	ve[2].clear();
	ve[3].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			ve[1].push_back(i);
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			ve[2].push_back(i);
		else
			ve[3].push_back(i);
	}
	sort(ve[1].begin(),ve[1].end(),cmp1);
	sort(ve[2].begin(),ve[2].end(),cmp2);
	sort(ve[3].begin(),ve[3].end(),cmp3);
	if(ve[1].size()>n/2)
	{
		int cnt=0;
		for(int j=0;j<ve[1].size();j++)
		{
			cnt++;
			ans+=max(a[ve[1][j]][2],a[ve[1][j]][3]);
			if(ve[1].size()-cnt<=n/2)
				break;
		}
		for(int j=cnt;j<ve[1].size();j++)
			ans+=a[ve[1][j]][1];
		for(int j=0;j<ve[2].size();j++)
			ans+=a[ve[2][j]][2];
		for(int j=0;j<ve[3].size();j++)
			ans+=a[ve[3][j]][3];
		cout<<ans<<"\n";
		return ;
	}
	if(ve[2].size()>n/2)
	{
		int cnt=0;
		for(int j=0;j<ve[2].size();j++)
		{
			cnt++;
			ans+=max(a[ve[2][j]][1],a[ve[2][j]][3]);
			if(ve[2].size()-cnt<=n/2)
				break;
		}
		for(int j=cnt;j<ve[2].size();j++)
			ans+=a[ve[2][j]][2];
		for(int j=0;j<ve[1].size();j++)
			ans+=a[ve[1][j]][1];
		for(int j=0;j<ve[3].size();j++)
			ans+=a[ve[3][j]][3];
		cout<<ans<<"\n";
		return ;
	}
	if(ve[3].size()>n/2)
	{
		int cnt=0;
		for(int j=0;j<ve[3].size();j++)
		{
			cnt++;
			ans+=max(a[ve[3][j]][1],a[ve[3][j]][2]);
			if(ve[3].size()-cnt<=n/2)
				break;
		}
		for(int j=cnt;j<ve[3].size();j++)
			ans+=a[ve[3][j]][3];
		for(int j=0;j<ve[1].size();j++)
			ans+=a[ve[1][j]][1];
		for(int j=0;j<ve[2].size();j++)
			ans+=a[ve[2][j]][2];
		cout<<ans<<"\n";
		return ;
	}
	for(int j=0;j<ve[1].size();j++)
		ans+=a[ve[1][j]][1];
	for(int j=0;j<ve[2].size();j++)
		ans+=a[ve[2][j]][2];
	for(int j=0;j<ve[3].size();j++)
		ans+=a[ve[3][j]][3];
	cout<<ans<<"\n";
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
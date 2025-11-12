#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n;
int a[N][3];
vector<int>pt[3];
int sum[N];
int ans=0;
bool cmp(int x,int y)
{
	return sum[x]<sum[y];
}
void work()
{
	cin>>n;
	ans=0;
	for(int i=0;i<3;i++)pt[i].clear();
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int j=0;j<3;j++)
		{
			if(a[i][j]>=a[i][0]&&a[i][j]>=a[i][1]&&a[i][j]>=a[i][2])
			{
				pt[j].push_back(i);
				ans+=a[i][j];
				break;
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		if((int)(pt[i].size())>n/2)
		{
			//cout<<i<<"__\n";
			for(auto j:pt[i])
			{
				sum[j]=1e18;
				for(int k=0;k<3;k++)
				{
					if(k!=i)sum[j]=min(sum[j],a[j][i]-a[j][k]);
				}
			}
			sort(pt[i].begin(),pt[i].end(),cmp);
			for(int j=0;j<(int)(pt[i].size())-n/2;j++)
			{
				//cout<<sum[pt[i][j]]<<",";
				ans-=sum[pt[i][j]];
			}
			break;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)work();
	return 0;
}

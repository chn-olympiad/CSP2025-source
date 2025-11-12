#include<bits/stdc++.h>
using namespace std;
struct node
{
	int n,id;
	bool operator < (node b)
	{
		return n<b.n;
	}
};
node a[100005][3];
vector<int>b[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j].n;
				a[i][j].id=j;
			}
			sort(a[i],a[i]+3);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][2].n;
			b[a[i][2].id].push_back(a[i][2].n-a[i][1].n);
		}
		for(int i=0;i<3;i++)
		{
			if(b[i].size()>n/2)
			{
				sort(b[i].begin(),b[i].end());
				for(int j=0;j<b[i].size()-n/2;j++)
				{
					ans-=b[i][j];
				}
			}
			b[i].clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//没加 ios 1.2s
//加了 ios 0.1s
//(-o-) 

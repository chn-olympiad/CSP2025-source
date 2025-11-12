#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
struct node
{
	int idx,v;
	bool operator<(const node x)const
	{
		return v<x.v;
	}
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof a);
		int n;
		long long ans=0;
		vector<node> p[4];
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			int k=0,maxn=-1,mm=-1;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>maxn)
				{
					mm=maxn;
					maxn=a[i][j];
					k=j;
				}
				else if(a[i][j]>mm)
				{
					mm=a[i][j];
				}
			}
			p[k].push_back({i,a[i][k]-mm});
			ans+=a[i][k];
		}
		
		for(int i=1;i<=3;i++)
		{
			if(p[i].size()>n/2)
			{
				sort(p[i].begin(),p[i].end());
				int len=p[i].size()-n/2;
				for(int j=0;j<len;j++)
				{
					int pos=p[i][j].idx,maxn=-1,x=0;
					for(int k=1;k<=3;k++)
					{
						if(k==i) continue;
						if(a[pos][k]>maxn)
						{
							maxn=a[pos][k];
							x=k;
						}
					}
					//p[x].push_back({pos,a[pos][x]});
					ans-=a[pos][i];
					ans+=a[pos][x];
				}
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

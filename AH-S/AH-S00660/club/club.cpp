#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001][4],maxx[100001],cmax[100001],z[100001];
vector<int> g[4];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3],maxx[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxx[i]==a[i][1])
				cmax[i]=max(a[i][2],a[i][3]);
			else
			{
				if(maxx[i]==a[i][2])
					cmax[i]=max(a[i][1],a[i][3]);
				else
					cmax[i]=max(a[i][1],a[i][2]);
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			int nowmax=maxx[i];
			s+=nowmax;
			if(nowmax==a[i][1])
				g[1].push_back(i);
			else
			{
				if(nowmax==a[i][2])
					g[2].push_back(i);
				else
					g[3].push_back(i);
			}
		}
		int len1=g[1].size(),len2=g[2].size(),len3=g[3].size(),l=n/2,top=0,c=0;
		if(len1>l)
		{
			for(auto i:g[1])
				z[++top]=maxx[i]-cmax[i];
			c=len1-l;
		}
		if(len2>l)
		{
			for(auto i:g[2])
				z[++top]=maxx[i]-cmax[i];
			c=len2-l;
		}
		if(len3>l)
		{
			for(auto i:g[3])
				z[++top]=maxx[i]-cmax[i];
			c=len3-l;
		}
		sort(z+1,z+top+1);
		for(int i=1;i<=c;i++)
			s-=z[i];
		cout<<s<<"\n";
		g[1].clear(),g[2].clear(),g[3].clear();
	}
	return 0;
}
